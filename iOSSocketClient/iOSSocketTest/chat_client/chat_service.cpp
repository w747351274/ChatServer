//
//  chat_service.cpp
//  iOSSocketTest
//
//  Created by 江磊 on 2018/10/08.
//  Copyright © 2018 江磊. All rights reserved.
//

#include "chat_service.hpp"
#include <iostream>

void chat_service::chatMsgReceive(const std::string &msg){
    std::cout << "chatMsgReceive ->" << msg << std::endl;
}

chat_service::chat_service():resolver_(io_context_){
    c_c_ = new  chat_client(io_context_,resolver_.resolve({"192.168.199.202","8002"}));
    c_c_-> recieveMessage.connect(boost::bind(&chat_service::chatMsgReceive, this,_1));
}

void chat_service::start_chat_service(){
    if(!c_c_->is_open()){
        c_c_->start_connect();
    }
    t_ = new std::thread([this](){
        if(this ->io_context_.stopped()){
            this ->io_context_.reset() ;
        }
        this ->io_context_.run();
    });
}

void chat_service::stop_chat_service() {
    if(c_c_->is_open()){
        c_c_->close();
        t_ -> join();
    }
}
chat_service::~ chat_service() {
    c_c_->recieveMessage.disconnect(boost::bind(&chat_service::chatMsgReceive, this,_1));
    delete c_c_;
    t_ -> join();
}
void chat_service::write(const chat_message& msg){
    c_c_ ->write(msg);
}
