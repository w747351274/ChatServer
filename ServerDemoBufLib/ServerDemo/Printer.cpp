//
//  Printer.cpp
//  ServerDemo
//
//  Created by 江磊 on 2018/10/05.
//  Copyright © 2018 江磊. All rights reserved.
//

#include "Printer.hpp"
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <iostream>
#include <vector>

class Printer {
public:
    Printer(boost::asio::io_service &io):strand_(io),timer(io,boost::posix_time::seconds(1)),count(0){
        timer.async_wait(strand_.wrap([this](const boost::system::error_code &error){
            if (error == boost::asio::error::operation_aborted) {
                std::cout << "cancel \n";
            }else{
                this -> print();
            }
        }));
    }
    ~Printer(){
        std::cout << "final count -> " << count << std::endl;
    }
    void print(){
        if (count < 5) {
            std::cout << "count -> " << count << std::endl;
            ++count;
            timer.expires_at(timer.expires_at() + boost::posix_time::seconds(1));
            timer.async_wait(strand_.wrap([this](const boost::system::error_code &e){
                if (e == boost::asio::error::operation_aborted) {
                    std::cout << "cancel \n";
                }else{
                    this -> print();
                }
            }));
        }
        
    }
private:
    boost::asio::deadline_timer timer;
    boost::asio::io_service::strand strand_;
    int count;
};

int printerMainTest(int argc, const char * argv[]) {
    boost::asio::io_service io;
    Printer printer(io);
    std::thread t([&io]{io.run();});
    t.join();
    return 0;
}
