//
//  OO.cpp
//  OOTest
//
//  Created by 江磊 on 2018/10/01.
//  Copyright © 2018 江磊. All rights reserved.
//

#include <stdio.h>
#include "OO.h"
#include <iostream>
#include "Event.hpp"

void Derived::act(Event const&) {
    
}
void Derived::print() {
    
}
void Grouped::act(Event const&) {
    
}
void Grouped::print() {
    
}
void Grouped::addBase(Base *){
    
}
void Grouped::removeBase(int cid){
    
}
int __main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cout << "Hello, World!\n";
    Derived *info = new Derived(1);
    Grouped * group = new Grouped(2);
    Event ev;
    
    group -> act(ev);
    group -> print();
    group -> addBase(info);
    group ->removeBase(info->cid());
    
    delete info;
    delete group;
    return 0;
}
