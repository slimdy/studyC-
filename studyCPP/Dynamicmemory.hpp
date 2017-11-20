//
//  Dynamicmemory.hpp
//  studyCPP
//
//  Created by slimdy on 2017/11/6.
//  Copyright © 2017年 slimdy. All rights reserved.
//

#ifndef Dynamicmemory_hpp
#define Dynamicmemory_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
class strBlob{
public:
    typedef vector<string>::size_type size_type;
    strBlob();
    strBlob(initializer_list<string> il);
    size_type size() const{
        return data->size();
    }
    bool empty() const {return data->empty();}
    void push_back(const string &t) const {
        data->push_back(t);
    }
    void pop_back();
    string &front();
    string &back();
private:
    shared_ptr<vector<string>> data; // shared_ptr 是智能指针 负责自动管理内存，它的实质是引用计数器，当引用计数为0是指针为空，所指内存销毁
    weak_ptr<vector<string>> wptr;
    size_t curr;
    void check(size_type i,const string &msg) const;
};
#endif /* Dynamicmemory_hpp */
