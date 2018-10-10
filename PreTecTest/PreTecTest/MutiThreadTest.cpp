//
//  MutiThreadTest.cpp
//  MapTest
//
//  Created by 江磊 on 2018/10/02.
//  Copyright © 2018 江磊. All rights reserved.
//

#include "MutiThreadTest.hpp"
#include <vector>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <pthread.h>
#include <thread>
#include <atomic>
double cacualate(double v){
    if (v <= 0) {
        return v;
    }
    //    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    return sqrt(v*v + std::sqrt((v - 5)*(v + 2.5))/v);
}


template <typename T1 , typename func>
double getValOfRange(std::thread::id id, T1 t1,T1 t2 ,func fun){
    auto curThredId = std::this_thread::get_id();
    if (curThredId == id) {
        std::cout << "hell no , it is mainThread  " << std::endl;
    }else{
        std::cout << "the thread is " << curThredId << std::endl;
    }
    
    double ret = 0;
    for(auto iter = t1 ; iter != t2 ; ++iter){
        ret += fun(*iter);
    }
    return ret;
}

int mutiThreadTestMain(){
    auto mainThreadId = std::this_thread::get_id();
    std::vector<double> vecTes(100000);
    for (int i = 0 ; i < 100000; i ++) {
        vecTes.push_back(rand());
    }
    std::cout << "vecTes Size ->" << vecTes.size() <<std::endl;
    double r1 = 0;
    auto clockbegin = clock();
    for (auto & v1 : vecTes) {
        r1 += cacualate(v1);
    }
    auto clockEnd = clock();
    std::cout << "mainThread v1 ->" << r1 <<" time is "<< (clockEnd - clockbegin) << std::endl;
    
    double r2 = 0;
    std::vector<double>::iterator begin = vecTes.begin();
    std::vector<double>::iterator end = vecTes.end();
    std::vector<double>::iterator half = vecTes.begin() + vecTes.size()/2;
    
    auto clockMBegin = clock();
    std::thread s([&r2,mainThreadId,begin,half](){
        r2 = getValOfRange(mainThreadId,begin, half,cacualate);
    });
    double r3 = getValOfRange(mainThreadId,half, end,cacualate);
    s.join();
    auto clockMEnd = clock();
    std::cout<< "result of mutil ->" << (r2 + r3) << "time is" << (clockMEnd - clockMBegin)<< std::endl;
    return 0;
}

void print(int a,int b, int c ){
    std::cout << a  << "  " << b << "  " << c << "\n";
}

void print2(int a,int b, const std::string &str ){
    std::cout << a  << "  " << b << "  " << str << "\n";
}

void add(int a , int b, int &c){
    c = a + b;
}

void printString(const std::string & s1,const std::string & s2){
    std::cout <<  s1 <<" " << s2 <<"\n";
};
void testInit(){
    int a = 3 ;
    int b = 4;
    int c = 5;
    std::thread t([=]{print(a, b, c);});
    std::string st("str kk");
    std::thread t2([=,&st]{
        print2(a, b, st);
    });
    
    std::thread t3([= , &c]{
        add(a, b, c);
    });
    
    std::cout << "t3 excute ->" << c << "\n" ;
    
    t.join();
    t2.join();
    t3.join();
    
    std::thread t4(add,a,b,std::ref(c));
    t4.join();
    std::cout << "t4 excute ->" << c << "\n" ;
    
    std::string st1("abc");
    std::string st2("efg");
    std::thread t5([&]{printString(st1, st2);});
    t5.join();
    std::thread t6(printString,std::cref(st1),std::cref(st2));
    t6.join();
}

//共享变量
class Counter {
public:
    void addCountAndResource(){
        std::lock_guard<std::mutex> lock(m_mutex);
        addCount();
        addResource(1);
    }
    int getCount(){
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_count;
    }
    int getAvarage(){
        std::lock_guard<std::mutex> lock(m_mutex);
        if (m_count == 0) {
            return 1;
        }
        return m_count/m_resource;
    }
    Counter():m_count(0),m_resource(0){
    }
private:
    void addCount(){
        m_count ++ ;
    }
    void addResource(int res){
        m_resource += res;
    }

    int m_count;
    int m_resource;
    std::mutex m_mutex;
};

bool printStep(Counter & counter,double max){
    double count = counter.getCount();
    if (counter.getAvarage() != 1) {
        std::cout << "there is something wrong \n";
    }
    if (count == max) {
        std::cout << "Yes finished \n" ;
        return true;
    }
    return false;
}

int work(int a){
    return  a + a;
}
template <typename T>
void doRealWork(T begin,T end,Counter & counter, double &value) {
    for (; begin != end; ++begin) {
        value += work(*begin);
        counter.addCountAndResource();
    }
}
int mutiThreadTestMain2(){
//    testInit();
    
    unsigned int threadCout = std::thread::hardware_concurrency();
    std::cout << threadCout << " concurrency is support" << std::endl;
    std::vector<int> vec;
    int maxSize = 100000;
    for (int i = 0; i < maxSize; i ++) {
        vec.push_back(rand() %100);
    }
    Counter counterSig;
    double totleVal1 = 0;
    
    doRealWork(vec.begin(), vec.end(), counterSig,totleVal1);
    std::cout << "singel thread count -> " << counterSig.getCount() << "totleVal1" << totleVal1 << std::endl;
    
    Counter counter;
    double totleVal2 = 0;
    auto t1 = vec.begin() + vec.size()/3;
    auto t2 = t1 + vec.size()/3;
    std::thread watchStep([&,maxSize]{
        pthread_setname_np("com.wjl.watchSetp");
        while (!printStep(counter, maxSize)) {};
    });
    
    std::thread thread1([&counter,&totleVal2,&vec,t1](){
        doRealWork(vec.begin(), t1, counter,totleVal2);
    });
    std::thread thread2([&counter,&totleVal2,t1,t2](){
        doRealWork(t1, t2, counter,totleVal2);
    });;
    doRealWork(t2, vec.end(), counter,totleVal2);
    thread1.join();
    thread2.join();
    std::cout << "mutil thread count -> " << counter.getCount() << "totleVal2" << totleVal2 << std::endl;
    watchStep.join();
    
    return 0;
}
class Banker {
public:
    Banker(){};
    ~Banker(){};
    int getCount(){
        return m_money;
    }
    void addAcount(int money){
        m_money += money;
    }
    void removeAcount(int money){
        m_money -= money;
    }
    
    std::mutex m_mutex;
private:
    int m_money;
};

void transferMoney(Banker &ban,Banker &ker,int money){
    std::lock(ban.m_mutex, ker.m_mutex);
//    std::lock_guard<std::mutex> lockGuardBan(ban.m_mutex,std::adopt_lock);
//    std::lock_guard<std::mutex> lockGuardKer(ker.m_mutex,std::adopt_lock);
    if (ban.getCount() < money) {
        return;
    }
    ban.removeAcount(money);
    ker.addAcount(money);
}
