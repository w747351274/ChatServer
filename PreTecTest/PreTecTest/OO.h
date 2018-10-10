//
//  OO.h
//  OOTest
//
//  Created by 江磊 on 2018/09/27.
//  Copyright © 2018 江磊. All rights reserved.
//

#ifndef OO_h
#define OO_h
#include <map>
class Event;

class Base {
public:
    Base(int cid): m_id(cid){};
    virtual ~Base() {}
    virtual void act(Event const&) = 0;
    virtual void print() = 0;
    virtual void update(){};
    int cid() const { return m_id; };
private:
    int m_id;
};

class Derived:public Base{
public:
    void act(Event const&) ;
    void print() ;
    Derived(int cid):Base(cid){};
    ~Derived(){};
private:
};

class Grouped:public Base {
public:
    void act(Event const&) ;
    void print() ;
    void addBase(Base *);
    void removeBase(int cid);
    
    Grouped(int cid):Base(cid){
        
    };
    ~Grouped(){
        
    };
    
private:
    std::map<int,Base *> m_info;
    
};
#endif /* OO_h */
