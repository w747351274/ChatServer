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

class chat_message {
public:
    enum { header_length = 4 + 4 + 4 + 4 + 4 };
    enum { max_body_length = 512};
    
    chat_message()
    : body_length_(0),clientVersion_(200) {
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
        if (body_length_ > max_body_length)
        body_length_ = max_body_length;
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
        char headLength[4 + 1] = "";
        char clientVersion[4 + 1] = "";
        char cmdId[4 + 1] = "";
        char seq[4 + 1] = "";
        char bodyLenth[4 + 1] = "";
        
        std::strncat(headLength, data_, 4);
        std::strncat(clientVersion, data_+ 4, 4);
        std::strncat(cmdId, data_ + 4 *2, 4);
        std::strncat(seq, data_ + 4 *3, 4);
        std::strncat(bodyLenth, data_ + 4 *4, 4);

        headLength_ = std::atoi(headLength);
        clientVersion_ = std::atoi(clientVersion);
        cmdId_ = std::atoi(cmdId);
        seq_ = std::atoi(seq);
        body_length_ = std::atoi(bodyLenth);
        
        std::cout << "headLength_ :"   << headLength_ << " clientVersion_:"  << clientVersion_  << " cmdId_:"  << cmdId_ << " seq_:" << seq_  << " bodyLenth_:" << body_length_ << std::endl;
 
        if (body_length_ > max_body_length) {
            body_length_ = 0;
            return false;
        }
        return true;
    }
    
    void encode_header() {
        char headLength[4 + 1] = "";
        std::sprintf(headLength , "%4d", static_cast<int>(header_length));
        std::memcpy(data_, headLength , 4);
        
        char clientVersion[4 + 1] = "";
        std::sprintf(clientVersion , "%4d", static_cast<int>(200));
        std::memcpy(data_ +4, clientVersion , 4);
        
        char cmdId[4 + 1] = "";
        std::sprintf(cmdId , "%4d", static_cast<int>(cmdId_));
        std::memcpy(data_ + 4*2, cmdId , 4);
        
        char seq[4 + 1] = "";
        std::sprintf(seq , "%4d", static_cast<int>(seq_));
        std::memcpy(data_+ 4*3, seq, 4);
        
        char body_length[4 + 1] = "";
        std::sprintf(body_length , "%4d", static_cast<int>(body_length_));
        std::memcpy(data_+ 4*4, body_length , 4);
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

