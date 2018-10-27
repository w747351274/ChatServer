//
//  chat_room.cpp
//  ServerDemo
//
//  Created by 江磊 on 2018/10/26.
//  Copyright © 2018 江磊. All rights reserved.
//

#include "chat_room.hpp"
#include "i_chat_participant.h"

void chat_room::join(chat_participant_ptr participant){
    participants_.insert(participant);
    for (auto msg: recent_msgs_)
        participant->deliver(msg);
}

void chat_room::leave(chat_participant_ptr participant){
    participants_.erase(participant);
}

void chat_room::push(const chat_message& msg , chat_participant_ptr participant){
    recent_msgs_.push_back(msg);
    while (recent_msgs_.size() > max_recent_msgs)
        recent_msgs_.pop_front();
    
    for (auto participant_: participants_){
        if (participant_ != participant) {
            participant_->deliver(msg);
        }
    }
    }
