//
// chat_message.hpp
// ~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2018 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef CHAT_MESSAGE_HPP
#define CHAT_MESSAGE_HPP

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stdint.h>
#include <stdlib.h>

static int CMDID_NOOPING = 6;
static int CMDID_NOOPING_RESP = 6;
static int CLIENTVERSION = 200;
static int MESSAGE_PUSH = 10001;

struct __STNetMsgXpHeader {
    uint32_t    head_length;
    uint32_t    client_version;
    uint32_t    cmdid;
    uint32_t    seq;
    uint32_t    body_length;
};

class chat_message {
public:
    enum { header_length = sizeof(__STNetMsgXpHeader) };
    enum { max_body_length = 512};
    
    chat_message()
    : body_length_(0),clientVersion_(CLIENTVERSION) {
    }
    
    const char* data() const {
        return data_;
    }
    
    char* data() {
        return data_;
    }
    
    std::size_t length() const {
        return header_length + body_length_;
    }
    
    const char* body() const {
        return data_ + header_length;
    }
    
    char* body() {
        return data_ + header_length;
    }
    
    std::size_t body_length() const {
        return body_length_;
    }
    
    void body_length(std::size_t new_length) {
        body_length_ = new_length;
    }
    
    int seq() const {
        return seq_;
    }
    
    void seq(int seq) {
        seq_ = seq;
    }
    
    int clientVersion() const {
        return clientVersion_;
    }
    int cmdId() const {
        return cmdId_;
    }
    void cmdId(int cmdId) {
        cmdId_ = cmdId;
    }
    std::size_t headLength() const {
        return headLength_;
    }
    void headLength(std::size_t headLength) {
        headLength_ = headLength;
    }
    
    
    bool decode_header() {
        
            __STNetMsgXpHeader st = {0};
        
        memcpy(&st, data_, sizeof(__STNetMsgXpHeader));
        
        headLength_ = ntohl(st.head_length);
        clientVersion_ = ntohl(st.client_version);
        cmdId_ = ntohl(st.cmdid);
        seq_ = ntohl(st.seq);
        body_length_ = ntohl(st.body_length);
  
        std::cout << "headLength_ :"   << headLength_ << " clientVersion_:"  << clientVersion_  << " cmdId_:"  << cmdId_ << " seq_:" << seq_  << " bodyLenth_:" << body_length_ << std::endl;
 
        return true;
    }
    
    void encode_header() {
        if (body() == nullptr && cmdId_ != CMDID_NOOPING && cmdId_ != CMDID_NOOPING_RESP) {
            return;
        }
        
        __STNetMsgXpHeader st = {0};
        st.head_length = htonl(sizeof(__STNetMsgXpHeader));
        st.client_version = htonl(CLIENTVERSION);
        st.cmdid = htonl(cmdId_);
        st.seq = htonl(seq_);
        st.body_length = htonl(body_length_);
        
        memcpy(data_, &st, sizeof(__STNetMsgXpHeader));
    }
    
private:
    char data_[header_length + max_body_length] ;
    std::size_t headLength_ ;
    int clientVersion_ ;
    int cmdId_ ;
    int seq_ ;
    std::size_t body_length_ ;
};

#endif // CHAT_MESSAGE_HPP

