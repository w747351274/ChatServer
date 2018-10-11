//
//  AsioTest.cpp
//  ServerDemo
//
//  Created by 江磊 on 2018/10/04.
//  Copyright © 2018 江磊. All rights reserved.
//

#include "AsioTest.hpp"
#include <vector>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/asio.hpp>
#include <boost/asio/steady_timer.hpp>
#include <iostream>

void print(const boost::system::error_code &e,std::shared_ptr<boost::asio::deadline_timer> st,int * count){
    if (*count < 5) {
        std::cout << *count << std::endl;
        ++(*count);
        st->expires_at(st->expires_at() +boost::posix_time::seconds(1));
        st -> async_wait([st,count](const boost::system::error_code &e){
            print(e, st, count);
        });
    }
}

void printL(const boost::system::error_code &e , boost::asio::steady_timer *st , int * count){
    if (*count < 5) {
        std::cout << *count << std::endl;
        ++(*count);
        st-> expires_from_now(std::chrono::seconds(1));
        st -> async_wait([st, count](const boost::system::error_code &e){
            printL(e, st, count);
        });
    }
}
void callback(const boost::system::error_code & e){
    std::cout << "callback hello my lady \n";
}

std::shared_ptr<boost::asio::deadline_timer>
registerPrint(boost::asio::io_service &io,int *count){
    auto t = std::make_shared<boost::asio::deadline_timer>(io,boost::posix_time::seconds(1));
    t->expires_at(t -> expires_at() + boost::posix_time::seconds(1));
    t->async_wait([t,count](const boost::system::error_code &e){
        print(e, t, count);
    });
    return t;
}

int asioMainTest(int argc, const char * argv[]) {
    // insert code here...
    boost::asio::io_service io;
//    boost::asio::steady_timer st(io);
//    st.expires_from_now(std::chrono::seconds(1));
//    st.async_wait([&st,&count](const boost::system::error_code &e){
//        printL(e, &st, &count);
//    });
//
    std::vector<int> vec;
    for (int i = 0; i < 5; ++i) {
        vec.push_back(i);
    }
    for (int i = 0; i < 5; ++i) {
        auto t = registerPrint(io,&vec[i]);
        std::cout << "pointer adress is -> " << t.get() << std::endl;
    }

    io.run();
    for (auto i  : vec) {
        std::cout << "final count is -> " << i  << std::endl;
    }
    return 0;
}
