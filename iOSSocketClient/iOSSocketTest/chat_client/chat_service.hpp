//
//  chat_service.hpp
//  iOSSocketTest
//
//  Created by 江磊 on 2018/10/08.
//  Copyright © 2018 江磊. All rights reserved.
//

#ifndef chat_service_hpp
#define chat_service_hpp

#include <stdio.h>
#include "chat_client.hpp"

class chat_service {
public:
    
    chat_service();
    void start_chat_service();
    void stop_chat_service();
    ~chat_service();
    void chatMsgReceive(const std::string &msg);
    void write(const chat_message& msg);
private:

    boost::asio::io_context io_context_;
    tcp::resolver resolver_;
    chat_client *c_c_;
    std::thread *t_;
};

#endif /* chat_service_hpp */
