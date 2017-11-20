//
//  Dynamicmemory.cpp
//  studyCPP
//
//  Created by slimdy on 2017/11/6.
//  Copyright © 2017年 slimdy. All rights reserved.
//

#include "Dynamicmemory.hpp"
strBlob::strBlob():data(make_shared<vector<string>>()){};
strBlob::strBlob(initializer_list<string> il):data(make_shared<vector<string>>(il)){};
void strBlob::check(size_type i , const string &msg) const{
    auto p = wptr.lock();
    if (!p) {
        throw runtime_error("ubound strBlobPtr");
    }
    if ( i >= data->size()) {
        throw out_of_range(msg);
    }
}
string& strBlob::back(){
    check(0, "back() 运行在空的strBlob上");
    return data->back();
}

string& strBlob::front(){
    check(0, "front() 运行在空的strBlob上");
    return data->front();
}

void strBlob::pop_back(){
    check(0, "pop_back() 运行在空的strBolob上");
    data->pop_back();
}


void studyDynamicMemory(){
    
    unique_ptr<string> up1(new string("hahaha"));
    
    unique_ptr<string> up2(up1.release());  //release把 up1保存的指针返回给 up2 然后up1的值置为空
    
    up2.reset();//up2释放所指对象
    
    
}
