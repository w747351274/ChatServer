//
//  TcpTest.cpp
//  ServerDemo
//
//  Created by 江磊 on 2018/10/05.
//  Copyright © 2018 江磊. All rights reserved.
//

#include "TcpTest.hpp"

#include <boost/array.hpp>
#include <boost/asio.hpp>

#include <iostream>

using boost::asio::ip::tcp ;
int tcpTestMain(int argc, const char * argv[]){
    try {
//        if (argc != 2) {
//            std::cerr << "usage client <host>" << std::endl;
//        }
        boost::asio::io_service io_service;
        tcp::resolver resolver(io_service);
//        tcp::resolver::query query(argv[1],"daytime");
        tcp::resolver::query query("time.nist.gov","daytime");
        tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
        
        tcp::socket socket(io_service);
        boost::asio::connect(socket, endpoint_iterator);
        for(;;){
            boost::array<char, 128> buff;
            boost::system::error_code error;
            size_t len = socket.read_some(boost::asio::buffer(buff),error);
            if (error == boost::asio::error::eof) {
                break;
            }else if (error)
                throw boost::system::system_error(error);
            std::cout.write(buff.data(), len);
        }
        
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
