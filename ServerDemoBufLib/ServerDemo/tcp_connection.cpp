//
//  tcp_connection.cpp
//  ServerDemo
//
//  Created by 江磊 on 2018/10/05.
//  Copyright © 2018 江磊. All rights reserved.
//

#include "tcp_connection.hpp"
#include <memory>
#include <iostream>
#include <string>
#include <functional>
#include <boost/asio.hpp>
#include <ctime>

using boost::asio::ip::tcp;

std::string make_day_time(){
    using namespace std;
    auto now = time(nullptr);
    return ctime(&now);
}

class tcp_connection:public std::enable_shared_from_this<tcp_connection> {
public:
    using pointer = std::shared_ptr<tcp_connection>;
    
    static pointer createConnection(boost::asio::io_service &io_service){
        return pointer(new tcp_connection(io_service));
//        return std::make_shared<tcp_connection>(io_service);
    }
    tcp::socket &socket(){
        return socket_;
    }
    void start(){
        buffer_ = make_day_time();
        auto self =  shared_from_this();
        std::cout << "start wirte \n";
        boost::asio::async_write(socket_, boost::asio::buffer(buffer_), [self = std::move(self)](auto &error,auto bytes_transferred){
            self -> handle_wirte(error, bytes_transferred);
        });
    }
private:
    tcp_connection(boost::asio::io_service &io_service):socket_(io_service){
    }
    void handle_wirte(const boost::system::error_code &e ,size_t){}
    std::string buffer_;
    tcp::socket socket_;
};

class tcp_server{
public:
    tcp_server(boost::asio::io_service &io_service):acceptor_(io_service , tcp::endpoint(tcp::v4(),8000)){
        start_accet();
    }
    
private:
    void start_accet(){
        auto new_connection = tcp_connection::createConnection(acceptor_.get_io_service());
        acceptor_.async_accept(new_connection->socket(),  [this, new_connection](auto error){
            this ->handleAccept(new_connection, error);
        });
    }
    void handleAccept(tcp_connection::pointer new_connection,const boost::system::error_code &error){
        if (!error) {
            new_connection->start();
        }
        start_accet();
    }
    tcp::acceptor acceptor_;
};

int tcp_connectionTest(int argc , const char * argv[]){
    try {
        boost::asio::io_service io_service;
        tcp_server server(io_service);
        io_service.run();
    } catch (std::exception &ecception) {
        std::cerr << ecception.what() << std::endl;
    }
    return 0;
}
