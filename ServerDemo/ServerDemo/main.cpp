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
#import <ifaddrs.h>
#include <iostream>
#include "chatServer.hpp"
#include "server.hpp"

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
    // Initialise the server.
 
    std::string address;
    struct ifaddrs *interfaces = NULL;
    struct ifaddrs *temp_addr = NULL;
    int success = 0;
    success = getifaddrs(&interfaces);
    if (success == 0) { // 0 表示获取成功
        temp_addr = interfaces;
        while (temp_addr != NULL) {
            if(temp_addr->ifa_addr->sa_family == AF_INET) {
                    if (strcmp(temp_addr->ifa_name, "en0") == 0) {
                    address = inet_ntoa(((struct sockaddr_in *)temp_addr->ifa_addr)->sin_addr);
                }
            }
            temp_addr = temp_addr->ifa_next;
        }
    }
    freeifaddrs(interfaces);
    
    std::thread threadHttpServer([&address,&argc,&argv](){
//        http::server::server s("192.168.199.202", "8080", ".");
        std::cout << "start httpServer "<< address <<" \n";
        http::server::server s(address, "8080", ".");
        s.run();
    });
//    std::thread threadChatServer([&argc,&argv](){
//        chatServerMain(argc, argv);
//    });
    chatServerMain(argc, argv);
    std::cout << "end test\n";
    return 0;
}
