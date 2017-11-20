//
//  copyMoDestoryFunction.cpp
//  studyCPP
//
//  Created by slimdy on 2017/11/17.
//  Copyright © 2017年 slimdy. All rights reserved.
//

#include "copyMoDestoryFunction.hpp"
PersonOne test(){
   
    
    PersonOne p2("slimdy","男","中国",27);
    PersonOne p3 = p2;
    return p3;
}
void studyCopyMoveDestoryFunc(){
//    PersonOne p3 = test();
//    HasPrt hp = HasPrt("hahaha");
//    HasPrtCustomCounter hpcc = HasPrtCustomCounter("我爱你你爱我么");
//    HasPrtCustomCounter hpcc1 = hpcc;
//    HasPrtCustomCounter hpcc2 ;
//    hpcc2 = hpcc;
    HasPrtSmartPointer hpsp = HasPrtSmartPointer("wocao");
    
    HasPrtSmartPointer hpsp1;
    hpsp1 = hpsp;
    
    cout << *(hpsp.ps) <<endl;
    cout << *(hpsp1.ps) <<endl;
    

}


