//
//  testEnd.cpp
//  ServerDemo
//
//  Created by 江磊 on 2018/10/04.
//  Copyright © 2018 江磊. All rights reserved.
//

#include "testEnd.hpp"
//
//  main.cpp
//  ServerDemo
//
//  Created by 江磊 on 2018/10/03.
//  Copyright © 2018 江磊. All rights reserved.
//

#include <iostream>
#include <vector>
#include <boost/bind.hpp>
#include <cassert>

class object {
public:
    virtual std::string debugName() const = 0;
    virtual ~object(){std::cout << "bye object\n"; };
};

class RealObject:public object {
public:
    std::string debugName() const{
        return  "realObject DebugName\n";
    }
    ~RealObject(){
        std::cout << "realObject bye \n";
    }
};

void testObject(const object & obj){
    std::cout << obj.debugName() << std::endl;
}

void testCase(){
    RealObject obj;
    testObject(obj);
    std::shared_ptr<RealObject> autoObj = std::make_shared<RealObject>();
    testObject(*autoObj);
    std::unique_ptr<object> uobj = std::make_unique<RealObject>();
    testObject(*uobj);
}

void printGroup(int * group,size_t size){
    assert(group);
    for (size_t i = 0; i < size; i ++) {
        std::cout << group[i] << std::endl;
    }
}

void forC(){
    int *group =( int *) malloc(sizeof(int)*10);
    if (group) { //需要检查是否malloc成功
        printGroup(group, 10);
    }
    free(group);
}

void forNew(){
    int * newGroup = new int[10];
    printGroup(newGroup, 10);
    delete[] newGroup;
}

void testInfo(){
    std::string info;
    if (info.empty()) {
    }
    std::cout << info << std::endl;
}
template <typename T>
void  removeVectVal(std::vector<T>& vec ,T value) {
    vec.erase(std::remove(vec.begin(), vec.end(), value), vec.end());
}

void testRemoveVecVal(){
    std::vector<int> vect;
    for (int  i = 0;  i < 100 ; i ++ ) {
        vect.push_back(rand() %10);
    }
    auto goupSize = vect.size();
    removeVectVal(vect, 0);
    auto afterRemove = vect.size();
    std::cout << " totle removed size -> " << goupSize - afterRemove << std::endl;
}

template <typename T,typename Func>
void foreach(const T &t,Func func) {
    std::for_each(std::begin(t), std::end(t), func);
}

int maxHuiwen(const char * buffer){
    size_t size = strlen(buffer) ;
    int maxLenth = 1;
    for (int i = 0; i < size; i ++) {
        char temp= buffer[i];
        for (int j = i + 1 ; j < size ; j ++) {
            char tempBuff= buffer[j];
            if(temp == tempBuff){
                int tmple = j - i +1;
                maxLenth = (maxLenth > tmple ? maxLenth : tmple);
                break;
            }
        }
    }
    return maxLenth;
}

int testEndMain(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "begin test\n";
    testCase();
    forC();
    forNew();
    testInfo();
    testRemoveVecVal();
    char testHUIWen[] = "abaabcddcba";
    int maxLen = maxHuiwen(testHUIWen);
    std::cout << "maxLen -> " << maxLen << std::endl;
    return 0;
}
