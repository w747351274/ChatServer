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
#include "chat.pb.h"
#include "main.pb.h"

using namespace chat::proto;
using boost::asio::ip::tcp;

//----------------------------------------------------------------------

typedef std::deque<chat_message> chat_message_queue;

//----------------------------------------------------------------------

class chat_participant {
public:
    virtual ~chat_participant() {}
    virtual void deliver(const chat_message& msg) = 0;
};

typedef std::shared_ptr<chat_participant> chat_participant_ptr;

//----------------------------------------------------------------------

class chat_room {
public:
    void join(chat_participant_ptr participant){
        participants_.insert(participant);
        for (auto msg: recent_msgs_)
            participant->deliver(msg);
    }
    
    void leave(chat_participant_ptr participant){
        participants_.erase(participant);
    }
    
    void deliver(const chat_message& msg){
        recent_msgs_.push_back(msg);
        while (recent_msgs_.size() > max_recent_msgs)
            recent_msgs_.pop_front();
        
        for (auto participant: participants_)
            participant->deliver(msg);
    }
    
private:
    std::set<chat_participant_ptr> participants_;
    enum { max_recent_msgs = 100 };
    chat_message_queue recent_msgs_;
};

//----------------------------------------------------------------------

class chat_session : public chat_participant,
public std::enable_shared_from_this<chat_session> {
public:
    chat_session(tcp::socket socket, chat_room& room)
    : socket_(std::move(socket)),
    room_(room){
    }
    
    void start() {
        room_.join(shared_from_this());
        do_read_header();
    }
    
    void deliver(const chat_message& msg){
        bool write_in_progress = !write_msgs_.empty();
        write_msgs_.push_back(msg);
        if (!write_in_progress) {
            do_write();
        }
    }
    
private:
    void do_read_header(){
        auto self(shared_from_this());
        boost::asio::async_read(socket_,
                                boost::asio::buffer(read_msg_.data(), chat_message::header_length),
                                [this, self](boost::system::error_code ec, std::size_t length)   {
                                    if (!ec && read_msg_.decode_header()) {
                                        if (read_msg_.cmdId() == CMDID_NOOPING) {
                                            handle_nooping();
                                        } else if(read_msg_.cmdId() == proto::CMD_ID_SEND_MESSAGE){
                                            handle_send_message();
                                        }else if(read_msg_.cmdId() == proto::CMD_ID_HELLO){
                                            handle_hello();
                                        }
                                    } else {
                                        room_.leave(shared_from_this());
                                    }
                                });
    }
    void handle_nooping(){
        auto self(shared_from_this());
        boost::asio::async_write(socket_, boost::asio::buffer(read_msg_.data(),
                                                              read_msg_.length()),
                                 [this, self](boost::system::error_code ec, std::size_t /*length*/) {
                                     if (!ec) {
                                         do_read_header();
                                     }else {
                                         room_.leave(shared_from_this());
                                     }
                                 });
    }
    void handle_send_message(){
        auto self(shared_from_this());
        boost::asio::async_read(socket_,
                                boost::asio::buffer(read_msg_.body(), read_msg_.body_length()),
                                [this, self](boost::system::error_code ec, std::size_t /*length*/){
                                    if (!ec){
                                        SendMessageRequest request;
                                        request.ParseFromString(read_msg_.body());
                                        std::cout << request.DebugString() << std::endl;
                                        int retCode = SendMessageResponse::ERR_OK;
                                        std::string errMsg = "congratulations, " + request.from();
                                        SendMessageResponse response;
                                        response.set_err_code(retCode);
                                        response.set_err_msg(errMsg);
                                        response.set_from(request.from());
                                        response.set_text(request.text());
                                        response.set_topic(request.topic());
                                        std::string res = response.SerializeAsString();
                                        read_msg_.body_length(res.length());
                                        read_msg_.encode_header();
                                        std::memcpy(read_msg_.body(), res.c_str(), read_msg_.body_length());
                                        room_.deliver(read_msg_);
                                        do_read_header();
                                    } else {
                                        room_.leave(shared_from_this());
                                    }
                                });
    }
    void handle_hello(){
        auto self(shared_from_this());
        boost::asio::async_read(socket_,
                                boost::asio::buffer(read_msg_.body(), read_msg_.body_length()),
                                [this, self](boost::system::error_code ec, std::size_t /*length*/){
                                    if (!ec){
                                        proto::HelloRequest request;
                                        request.ParseFromString(read_msg_.body());
                                        std::cout << request.DebugString() << std::endl;
                                        int retCode = 0;
                                        std::string errMsg = "hello mars";

                                         proto::HelloResponse response;
                                        response.set_retcode(retCode);
                                        response.set_errmsg(errMsg);
 
                                        std::string res = response.SerializeAsString();
                                        read_msg_.body_length(res.length());
                                        read_msg_.encode_header();
                                        std::memcpy(read_msg_.body(), res.c_str(), read_msg_.body_length());
                                        room_.deliver(read_msg_);
                                        do_read_header();
                                    } else {
                                        room_.leave(shared_from_this());
                                    }
                                });
    }
    
    void do_write(){
        auto self(shared_from_this());
        boost::asio::async_write(socket_,
                                 boost::asio::buffer(write_msgs_.front().data(),
                                                     write_msgs_.front().length()),
                                 [this, self](boost::system::error_code ec, std::size_t /*length*/) {
                                     if (!ec) {
                                         write_msgs_.pop_front();
                                         if (!write_msgs_.empty()) {
                                             do_write();
                                         }
                                     } else {
                                         room_.leave(shared_from_this());
                                     }
                                 });
    }
    
    tcp::socket socket_;
    chat_room& room_;
    chat_message read_msg_;
    chat_message_queue write_msgs_;
};

//----------------------------------------------------------------------

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
