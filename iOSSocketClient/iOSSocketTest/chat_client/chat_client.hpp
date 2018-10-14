//
//  chat_client.hpp
//  iOSSocketTest
//
//  Created by 江磊 on 2018/10/06.
//  Copyright © 2018 江磊. All rights reserved.
//

#ifndef chat_client_hpp
#define chat_client_hpp

#include <stdio.h>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <thread>
#include <boost/asio.hpp>
#include "chat_message.hpp"
#include "boost/signals2.hpp"

using boost::asio::ip::tcp;

typedef std::deque<chat_message> chat_message_queue;

class chat_client {
public:
    boost::signals2::signal<void (const std::string& msg)> recieveMessage;
    chat_client(boost::asio::io_context& io_context,
                tcp::resolver::results_type endpoints)
    : io_context_(io_context),
    socket_(io_context),endpoints_ (endpoints){
    }
    void start_connect();
    void write(const chat_message& msg);
    
    void close();
    
    const bool is_open() const {
        return socket_.is_open() ;
    }
private:
    void do_connect(const tcp::resolver::results_type& endpoints);
    void do_read_header();
    void do_read_body();
    void do_write();
    
private:
    tcp::resolver::results_type endpoints_;
    boost::asio::io_context& io_context_;
    tcp::socket socket_;
    chat_message read_msg_;
    chat_message_queue write_msgs_;
};

#endif /* chat_client_hpp */
