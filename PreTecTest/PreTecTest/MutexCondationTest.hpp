//
//  MutexCondationTest.hpp
//  MapTest
//
//  Created by 江磊 on 2018/10/03.
//  Copyright © 2018 江磊. All rights reserved.
//

#ifndef MutexCondationTest_hpp
#define MutexCondationTest_hpp

#include <stdio.h>
#include <string>
class Message {
public:
    Message (std::string data):m_data(std::move(data)){
    }
    const std::string& getData() const{
        return m_data;
    }
    Message(){
    }
private:
    std::string m_data;
};

int mutexCondationTest();

#endif /* MutexCondationTest_hpp */
