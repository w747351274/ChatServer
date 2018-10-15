//
//  conversationListCgi.hpp
//  ServerDemo
//
//  Created by 江磊 on 2018/10/21.
//  Copyright © 2018 江磊. All rights reserved.
//

#ifndef conversationListCgi_hpp
#define conversationListCgi_hpp

#include <stdio.h>
#include <string>
#include "reply.hpp"
#include "request.hpp"

class conversation_list_cgi {
public:
    void handle_request(const http::server::request& req, http::server::reply& rep);
    conversation_list_cgi():path_("/mars/getconvlist"){
        
    }
    ~conversation_list_cgi(){
    }
    std::string getPath(){
        return path_;
    }
private:
    std::string path_;
};

#endif /* conversationListCgi_hpp */
