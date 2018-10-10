//
//  MutexCondationTest.cpp
//  MapTest
//
//  Created by 江磊 on 2018/10/03.
//  Copyright © 2018 江磊. All rights reserved.
//

#include "MutexCondationTest.hpp"
#include <list>
#include <vector>
#include <iostream>
#include <thread>

std::list<Message> globalList;
std::mutex globalMutex;
std::atomic<bool> isReady;
std::atomic<bool> quit;
std::condition_variable cv;

void work(){
    while (!isReady) {
    }
    while (!quit) {
        std::unique_lock<std::mutex> lock(globalMutex);
        cv.wait(lock, []{
            return !globalList.empty()||quit;
        });
        if (globalList.empty()) continue;
        auto iter = globalList.begin();
        std::cout << "global list -> " <<(*iter).getData() << std::endl;
        globalList.erase(iter);
    }
}

int mutexCondationTest(){
    const auto threadCount = 4;
    for (int i = 0; i < 10000 ; i ++) {
        globalList.push_back("this list num " + std::to_string(i));
    }
    std::vector<std::thread> pool;
    for (int i = 0; i < threadCount; i++) {
        pool.emplace_back(work);
    }
    isReady = true;
    for (int i = 0; i < 10000 ; i ++) {
        std::lock_guard<std::mutex> lock(globalMutex);
        globalList.push_back("this list num " + std::to_string(i));
        cv.notify_one();
    }
    while (true) {
        std::lock_guard<std::mutex> lock(globalMutex);
        if (globalList.empty()) {
            quit = true;
            cv.notify_all();
            break;
        }
    }
    for (auto & v : pool) {
        if (v.joinable()) {
            v.join();
        }
    }
    return 1;
}
