//
//  main.cpp
//  ServerDemo
//
//  Created by 江磊 on 2018/10/03.
//  Copyright © 2018 江磊. All rights reserved.
//
#include "AsioTest.hpp"
#include "TcpTest.hpp"
#include "TimerServer.hpp"
#include "Printer.hpp"
#include "tcp_connection.hpp"
#include "echo_service.hpp"
#include <iostream>
#include "chatServer.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "begin test\n";
//    argv[1] = "nist.time.gov";
//    tcpTestMain(argc, argv);
//    asioMainTest(argc, argv);
//    printerMainTest(argc, argv);
//    mainTimeServer();
//    tcp_connectionTest(argc, argv);

//    echoMain(argc, argv);
    chatServerMain(argc, argv);
    
    std::cout << "end test\n";
    return 0;
}
