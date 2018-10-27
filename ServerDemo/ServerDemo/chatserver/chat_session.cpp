//
//  chat_session.cpp
//  ServerDemo
//
//  Created by 江磊 on 2018/10/26.
//  Copyright © 2018 江磊. All rights reserved.
//

#include "chat_session.hpp"
#include "messagepush.pb.h"
#include "chat.pb.h"
#include "main.pb.h"

using namespace chat::proto;

void chat_session::start() {
    room_.join(shared_from_this());
    do_read_header();
}

void chat_session::deliver(const chat_message& msg){
    bool write_in_progress = !write_msgs_.empty();
    write_msgs_.push_back(msg);
    if (!write_in_progress) {
        do_write();
    }
}

void chat_session::do_read_header(){
    auto self(shared_from_this());
    boost::asio::async_read(socket_,
                            boost::asio::buffer(read_msg_.data(), chat_message::header_length),
                            [this, self](boost::system::error_code ec, std::size_t length)   {
                                if (!ec && read_msg_.decode_header()) {
                                    if (read_msg_.cmdId() == CMDID_NOOPING) {
                                        handle_nooping();
                                    } else if(read_msg_.cmdId() == proto::CMD_ID_SEND_MESSAGE){
                                        handle_send_message();
                                    }else if(read_msg_.cmdId() == 8){
                                        handle_hello2();
                                    }else if(read_msg_.cmdId() == proto::CMD_ID_HELLO){
                                        handle_hello();
                                    }
                                } else {
                                    room_.leave(shared_from_this());
                                }
                            });
}
void chat_session::handle_nooping(){
    auto self(shared_from_this());
    boost::asio::async_write(socket_, boost::asio::buffer(read_msg_.data(),
                                                          read_msg_.header_length),
                             [this, self](boost::system::error_code ec, std::size_t /*length*/) {
                                 if (!ec) {
                                     do_read_header();
                                 }else {
                                     room_.leave(shared_from_this());
                                 }
                             });
}

void chat_session::handle_send_message(){
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
                                    boost::asio::async_write(socket_, boost::asio::buffer(read_msg_.data(), read_msg_.length()) ,
                                                             [this,self](boost::system::error_code error , size_t){
                                                             });
                                    std::thread threadPush([this,self,&response](){
                                        MessagePush message_push;
                                        message_push.set_topic(response.topic());
                                        message_push.set_from(response.from());
                                        message_push.set_content(response.text());
                                        std::string resMessage = message_push.SerializeAsString();
                                        chat_message chatMsg;
                                        std::memcpy(chatMsg.body(), resMessage.c_str(), resMessage.length());
                                        chatMsg.cmdId(MESSAGE_PUSH);
                                        chatMsg.seq(PUSH_DATA_TASKID);
                                        chatMsg.body_length(resMessage.length());
                                        chatMsg.encode_header();
                                        room_.push(chatMsg,self);
                                    });
                                    threadPush.join();
                                    do_read_header();
                                } else {
                                    room_.leave(shared_from_this());
                                }
                            });
}
void chat_session::sendResponse(const std::string & user){
    int retCode = 0;
    std::string errMsg = "congratulations, "+ user;
    
    proto::HelloResponse response;
    response.set_retcode(retCode);
    response.set_errmsg(errMsg);
    
    std::string res = response.SerializeAsString();
    read_msg_.body_length(res.length());
    read_msg_.encode_header();
    std::memcpy(read_msg_.body(), res.c_str(), read_msg_.body_length());
    auto self(shared_from_this());
    boost::asio::async_write(socket_, boost::asio::buffer(read_msg_.data(),read_msg_.length()), [this, self](boost::system::error_code err,size_t){
        if (!err) {
            do_read_header();
        }else{
            room_.leave(shared_from_this());
        }
    });
}
void chat_session::handle_hello(){
    auto self(shared_from_this());
    boost::asio::async_read(socket_,
                            boost::asio::buffer(read_msg_.body(), read_msg_.body_length()),
                            [this, self](boost::system::error_code ec, std::size_t /*length*/){
                                if (!ec){
                                    proto::HelloRequest request;
                                    request.ParseFromString(read_msg_.body());
                                    std::cout << request.DebugString() << std::endl;
                                    sendResponse(request.user());
                                } else {
                                    room_.leave(shared_from_this());
                                }
                            });
}
void chat_session::handle_hello2(){
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
                                    boost::asio::async_write(socket_, boost::asio::buffer(read_msg_.data(),read_msg_.length()), [this, self](boost::system::error_code err,size_t){
                                        if (!err) {
                                            do_read_header();
                                        }else{
                                            room_.leave(shared_from_this());
                                        }
                                    });
                                    do_read_header();
                                } else {
                                    room_.leave(shared_from_this());
                                }
                            });
}

void chat_session::do_write(){
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
