//
//  chat_room.hpp
//  ServerDemo
//
//  Created by 江磊 on 2018/10/26.
//  Copyright © 2018 江磊. All rights reserved.
//

#ifndef chat_room_hpp
#define chat_room_hpp

#include <stdio.h>
#include <memory>
#include <set>
#include <deque>
#include "i_chat_participant.h"
#include "chat_message.hpp"

typedef std::shared_ptr<chat_participant> chat_participant_ptr;
typedef std::deque<chat_message> chat_message_queue;

class chat_room {
public:
    void join(chat_participant_ptr participant);
    
    void leave(chat_participant_ptr participant);
    
    void push(const chat_message& msg , chat_participant_ptr participant);
    
private:
    std::set<chat_participant_ptr> participants_;
    enum { max_recent_msgs = 100 };
    chat_message_queue recent_msgs_;
};

#endif /* chat_room_hpp */
