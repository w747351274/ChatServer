//
//  conversationListCgi.cpp
//  ServerDemo
//
//  Created by 江磊 on 2018/10/21.
//  Copyright © 2018 江磊. All rights reserved.
//

#include "conversationListCgi.hpp"
#include "mime_types.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include "main.pb.h"

void conversation_list_cgi::handle_request(const http::server::request& req, http::server::reply& rep){
    rep.status = http::server::reply::ok;
    proto::ConversationListResponse list;
    
    proto::Conversation* conversion = list.add_list();
    conversion -> set_name("wjl");
    conversion -> set_topic("topic");
    conversion -> set_notice("cpp");
    
    proto::Conversation* conversion2 = list.add_list();
    conversion2 -> set_name("wjl2");
    conversion2 -> set_topic("topic2");
    conversion2 -> set_notice("lua");
    
    rep.content.append(list.SerializeAsString());
    rep.headers.resize(2);
    rep.headers[0].name = "Content-Length";
    rep.headers[0].value = std::to_string(rep.content.size());
    rep.headers[1].name = "Content-Type";
    rep.headers[1].value =  "text/plain";
}
