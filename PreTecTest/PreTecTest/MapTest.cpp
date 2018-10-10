//
//  MapTest.cpp
//  MapTest
//
//  Created by 江磊 on 2018/10/01.
//  Copyright © 2018 江磊. All rights reserved.
//

#include "MapTest.hpp"
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

void vectorTest(){
    std::cout << "begin Test !\n";
    std::vector<int> vecT (10, 4);
    vecT.reserve(20);
    vecT.insert(vecT.end(), 5);
    
    auto begin = vecT.begin();
    std::vector<int>::iterator end = vecT.end();
    for (; begin  != end ; ++begin) {
        std::cout << "cout vec -> " << *begin <<std::endl;
    }
    
    std::vector<int>::iterator obj = find(vecT.begin(),vecT.end(),5) ;
    if (obj != vecT.end()) {
        long position = distance(vecT.begin(),obj);
        std::cout << "find 5 position ->" << position << std::endl;
    }
}
template <class Map>
typename Map::mapped_type  get_default(
                                       const Map &map,
                                       const typename Map::key_type &key,
                                       const typename Map::mapped_type &defau = typename Map::mapped_type()) {
    auto pos = map.find(key);
    return (pos != map.end() ? pos -> second:defau);
}

void testMap(){
    using map =  std::map<int ,std::string>;
    map m1;
    map m2(m1);
    map m3 = m1;
    map m4 = {m3.begin(),m3.end()};
    map g = {{1,"aaa"},{2,"bbb"},{2,"eee"},{3,"ccc"},{4,"eee"},{5,"ffff"}};
    if (g.empty()) {
        std::cout <<"is Empty" << std::endl;
    }else{
        std::cout <<"is not Empty" << std::endl;
    }
    g.insert(std::make_pair(100, "excellent"));
    g.emplace(101,"you a");
    g.emplace(std::make_pair(102, "i found c pp"));
    auto num = g.count(2);
    std::cout << "find a iterator val ->" << num << std::endl;
    auto findIter = g.find(101);
    if (findIter == std::end(g)) {
        std::cout << "not find a iterator" << std::endl;
    }else{
        std::cout << "find a iterator val ->" << findIter -> second << std::endl;
    }
    auto info = get_default(g, 102,"error");
    if (info.empty()) {
        std::cout << "get_default is empty" << std::endl;
    }else{
        std::cout << "get_default val ->" << info << std::endl;
    }
}

int mapTestMain(int argc, const char * argv[]) {
    // insert code here.
    testMap();
    return 0;
}
