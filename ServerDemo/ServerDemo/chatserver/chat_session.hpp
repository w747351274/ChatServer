//
//  chat_session.hpp
//  ServerDemo
//
//  Created by 江磊 on 2018/10/26.
//  Copyright © 2018 江磊. All rights reserved.
//

#ifndef chat_session_hpp
#define chat_session_hpp

#include <stdio.h>
#include <memory>
#include <set>
#include <utility>
#include <boost/asio.hpp>
#include "chat_message.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <boost/asio.hpp>
#include "i_chat_participant.h"
#include <boost/asio.hpp>
#include "chat_room.hpp"

typedef std::deque<chat_message> chat_message_queue;
using boost::asio::ip::tcp;

class chat_session : public chat_participant,
public std::enable_shared_from_this<chat_session> {
public:
    explicit chat_session(tcp::socket socket, chat_room& room)
    : socket_(std::move(socket)),
    room_(room){
    }
    
    void start() ;
    
    void deliver(const chat_message& msg);
    
private:
    void do_read_header();
    
    void handle_nooping();
    
    void handle_send_message();
    
    void sendResponse(const std::string & user);
    
    void handle_hello();
    
    void handle_hello2();
    
    void do_write();
    
    tcp::socket socket_;
    chat_room& room_;
    chat_message read_msg_;
    chat_message_queue write_msgs_;
};

#endif /* chat_session_hpp */
