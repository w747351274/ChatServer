//
//  chat_message.h
//  ServerDemo
//
//  Created by 江磊 on 2018/10/06.
//  Copyright © 2018 江磊. All rights reserved.
//

#ifndef chat_message_h
#define chat_message_h

#include <cstdio>
#include <cstdlib>
#include <cstring>

class chat_message {
public:
    enum { header_length = 4 };
    enum { max_body_length = 512 };
    
    chat_message():body_length_(0){
    }
    char *data(){
        return data_;
    }
    const char *data() const {
        return data_;
    }
    
    std::size_t length() const {
        return header_length + body_length_;
    }
    
    const char * body() const {
        return data_ + header_length;
    }
    
    char * body(){
        return data_ + header_length;
    }
    std::size_t body_length() const {
        return body_length_;
    }
    
    void body_length(std::size_t new_size){
        body_length_ = new_size;
        if (body_length_ > max_body_length) {
            body_length_ = max_body_length;
        }
    }
    
    bool decode_header(){
        char header[header_length + 1] = "";
        std::strncat(header, data_, header_length);
        size_t header_Size = std::atoi (data_ );
        if (header_Size > max_body_length) {
            return false;
        }
        return true;
    }
    void encode_header(){
        char header[header_length + 1] = "";
        std::sprintf(header, "%4d", static_cast<int>(body_length_));
        memcpy(data_, header, header_length);
    }
    
private:
    char data_[header_length + max_body_length];
    std::size_t body_length_;
};

#endif /* chat_message_h */
