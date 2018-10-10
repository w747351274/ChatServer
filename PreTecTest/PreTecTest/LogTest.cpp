//
//  LogTest.cpp
//  MapTest
//
//  Created by 江磊 on 2018/10/02.
//  Copyright © 2018 江磊. All rights reserved.
//

#include "LogTest.hpp"
static Log log(1 , "test.log");
void test(){
    log.log("hello my lady ");
}

void test1(){
//    static Log log(2 , "test.log");
    log.log("world");
}

void logTestMain(){
    test();
    test1();
}

