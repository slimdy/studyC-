//
//  dataType.hpp
//  studyCPP
//
//  Created by slimdy on 2017/9/29.
//  Copyright © 2017年 slimdy. All rights reserved.
//

#ifndef dataType_hpp
#define dataType_hpp
#include <iostream>
#include <stdio.h>

int SizeOfTypes();
int lvalueReference();
int pointer();
int constantStudy();
int typeAlias();
int studyStruct();
struct Sales_data{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    Sales_data(std::string bookNum,unsigned a,double b){
        bookNo = bookNum;
        units_sold = a;
        revenue = b;
    }
};
#endif /* dataType_hpp */
