//
//  TimerServer.cpp
//  ServerDemo
//
//  Created by 江磊 on 2018/10/05.
//  Copyright © 2018 江磊. All rights reserved.
//

#include "TimerServer.hpp"

#include <boost/asio.hpp>

#include <iostream>
#include <string>
#include <ctime>

using boost::asio::ip::tcp;

std::string make_daytime_string(){
    using namespace std;
    auto now = time(nullptr);
    return ctime(&now);
}

int mainTimeServer(){
    try {
        boost::asio::io_service io;
        
        tcp::acceptor acceptor(io,tcp::endpoint(tcp::v4(),8000));
        std::cout << "start the service" <<std::endl;
        for ( ;  ;  ) {
            tcp::socket socket(io);
            acceptor.accept(socket);
            std::string msgTime = make_daytime_string();
            
            boost::system::error_code ignored_code;
            boost::asio::write(socket, boost::asio::buffer(msgTime),ignored_code);
            std::cout << "connect" << std::endl;
        }
    } catch (std::exception except) {
        std::cerr << except.what() << std::endl;
    }
    std::cout << "end service \n";
    return 1;
}
