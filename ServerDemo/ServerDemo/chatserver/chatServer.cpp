//
//  chatServer.cpp
//  ServerDemo
//
//  Created by 江磊 on 2018/10/06.
//  Copyright © 2018 江磊. All rights reserved.
//


#include <cstdlib>
#include <deque>
#include <iostream>
#include <list>
#include <memory>
#include <set>
#include <utility>
#include <boost/asio.hpp>
#include "chat_message.hpp"
#include "chat_room.hpp"
#include "chat_session.hpp"

using boost::asio::ip::tcp;

class chat_server {
public:
    chat_server(boost::asio::io_context& io_context,
                const tcp::endpoint& endpoint)
    : acceptor_(io_context, endpoint){
        do_accept();
    }

private:
    void do_accept(){
        acceptor_.async_accept(
                               [this](boost::system::error_code ec, tcp::socket socket) {
                                   if (!ec) {
                                       std::make_shared<chat_session>(std::move(socket), room_)->start();
                                   }
                                   do_accept();
                               });
    }
    
    tcp::acceptor acceptor_;
    chat_room room_;
};

//----------------------------------------------------------------------

int chatServerMain(const char argc, const char * argv[]){
    boost::asio::io_service io_service;
    short port = 8081;
    chat_server chatServer(io_service,tcp::endpoint(tcp::v4(),port));
    std::cout << "start chatMsg  "<<boost::asio::ip::host_name()<<"listen port : "<< port << "\n" ;
    io_service.run();
    return 1;
}
