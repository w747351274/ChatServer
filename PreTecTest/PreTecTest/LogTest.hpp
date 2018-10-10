//
//  LogTest.hpp
//  MapTest
//
//  Created by 江磊 on 2018/10/02.
//  Copyright © 2018 江磊. All rights reserved.
//

#ifndef LogTest_hpp
#define LogTest_hpp

#include <stdio.h>
#include <fstream>
#include <iostream>

class Log {
public:
    Log(int id, const std::string &fileName):m_id(id){
        stream.open(fileName.c_str(),std::fstream::out);
    }
    void log(const std::string &info){
        std::cout << info << std::endl;
        stream << info;
        stream.flush();
    }
    ~Log(){
        std::cout << "bye log " << m_id << std::endl;
    }
private:
    int m_id;
    std::fstream stream;
};

void logTestMain();

#endif /* LogTest_hpp */
