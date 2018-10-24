//
//  main.cpp
//  OOTest
//
//  Created by 江磊 on 2018/09/27.
//  Copyright © 2018 江磊. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include "MutiThreadTest.hpp"
#include "LogTest.hpp"
#include "MutexCondationTest.hpp"
#include <cstdio>
#include <cstdlib>
#include <cstring>


int main(int argc, const char * argv[]) {
    // insert code here.
//    mutiThreadTestMain2();
//    logTestMain();
    //    mutexCondationTest();
    char msg[] = "asdfghjklqwertyuiopzxcvbnm";
//    std::cout << msg + 3 <<std::endl;
    
    char data_[100] = "002002000006";
//    data_ = "002002000006";
    std::size_t headLength_ ;
    int clientVersion_ ;
    int cmdId_ ;
    int seq_ ;
    std::size_t body_length_ ;
    
    char headLength[4 + 1];
    char clientVersion[4 + 1] ;
    char cmdId[4 + 1] ;
    char seq[4 + 1] ;
    char bodyLenth[4 + 1];
    
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
    return 0;
}
