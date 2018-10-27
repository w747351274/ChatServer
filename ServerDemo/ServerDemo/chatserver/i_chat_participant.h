//
//  i_chat_participant.h
//  ServerDemo
//
//  Created by 江磊 on 2018/10/26.
//  Copyright © 2018 江磊. All rights reserved.
//

#ifndef i_chat_participant_h
#define i_chat_participant_h

//----------------------------------------------------------------------
class chat_message;

class chat_participant {
public:
    virtual ~chat_participant() {}
    virtual void deliver(const chat_message& msg) = 0;
};

#endif /* i_chat_participant_h */
