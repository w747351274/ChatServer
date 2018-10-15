//
//  echo_service.cpp
//  ServerDemo
//
//  Created by 江磊 on 2018/10/06.
//  Copyright © 2018 江磊. All rights reserved.
//

#include "echo_service.hpp"

#include <boost/asio.hpp>

#include <memory>
#include <string>
#include <iostream>
#include <boost/array.hpp>

using boost::asio::ip::tcp;
class Session:public std::enable_shared_from_this<Session>{
public:
    Session(tcp::socket socket) : socket_(std::move(socket)){
    }
    void start() { do_read(); }

private:
    void do_read(){
        auto self(shared_from_this());
       socket_.async_read_some(boost::asio::buffer(data,max_length),
                               [this, self](auto error,std::size_t length){
                                   if (!error) {
                                       std::cout << "start read data" <<std::endl;
                                       std::cout.write(data, length);
                                       self -> do_wirte(length);
                                   }
       });
    }
    void do_wirte(std::size_t size){
        auto self(shared_from_this());
        socket_.async_write_some(boost::asio::buffer(data,size), [this,self](auto &error,std::size_t length){
            self ->do_read();
        });
    }

    tcp::socket socket_;
    enum {max_length = 1024};
    char data[max_length];
};

class Server {
public:
    Server(boost::asio::io_context &io_service,short port):acceptor_(io_service,tcp::endpoint(tcp::v4(),port)),socket_(io_service){
    }
    void start(){
        do_accept();
    }
    void do_accept(){
        acceptor_.async_accept(socket_, [this](auto error){
            if (!error) {
                auto newSession =  std::make_shared<Session>(std::move(socket_));
                newSession -> start();
            }
            do_accept();
        });
    }
private:
    tcp::acceptor acceptor_;
    tcp::socket socket_;
};

int echoMain(int argc ,const char *argv[]){
    boost::asio::io_context io_service;
    Server server(io_service,8081);
    server.start();
    std::cout << "echo server run \n";
    io_service.run();
    return 0;
}
