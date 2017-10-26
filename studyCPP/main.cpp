//
//  main.cpp
//  studyCPP
//
//  Created by slimdy on 2017/9/28.
//  Copyright © 2017年 slimdy. All rights reserved.
//

#include <iostream> //iostream中包含着几种输入和输出的方法，命名空间是std
#include "dataType.hpp"
#include "stringVectorArray.hpp"
#include "expression.hpp"
#include "studyFunction.hpp"
#include "studyClass.hpp"
#include "studyIO.hpp"
#include "studyContainer.hpp"
using namespace std;//如果添加这个使用的命名空间，则代码中不必分要使用std::

int simpleIO(){
    /*
     *cout是输出对象 ‘<<’是输出运算符 他的含义是把右边的内容写入到左边的对象 并返回一个输出对象
     *cin 是输入对象 ‘>>’是输入运算符 它的含义是把左边输入对象读取出赋予右边的对象，继续返回一个输入对象
     *endl 是操作符的一个特殊值，表示结束当前行，并且刷新缓存，将内存中的值刷新到设备中
     *<< >> 可以传入很多不同的数据类型。
     */
    cout << "Enter two numbers :" << std::endl;
    int v1 = 0;
    int v2 = 0;
    std::cin >> v1 >> v2 ;
    std::cout << "the sum of "<< v1 << " and "<< v2 << " is "<< v1+v2 <<std::endl;
    return 0;
}

int studyComments(){
    cout<<"*/";
    cout<<"/*";
    return 0;
}

int controlStream(){
    int sum = 0;
//    int val = 1;
////    while (val <= 100) {
////        sum+=val;
////        ++val;
////    }
    for (int val = 1; val <= 100; ++val) {
        sum+=val;
    }
    std::cout << "sum of 1 to 100 inclusive is " << sum << std::endl;
    
    return 0;
}
int theNumberOfUserCin(){
    int sum = 0, val = 0;
    while (std::cin >> val) sum  += val;
    std::cout << "the number you cined inclusive is "<< sum << std::endl;
    return 0;
    
}

int countWhatYouCin(){
    int val = 0,currntVal = 0;
    
    if (std::cin >> currntVal) {
        int cnt = 1;
        while (std::cin >> val) {
            if (val == currntVal) ++cnt;else {
                std::cout<<currntVal<<" occurs "<<cnt<<" times "<<std::endl;
                currntVal = val;
                cnt = 1;
            }
        }
        std::cout<<currntVal<<" occurs "<<cnt<<" times "<<std::endl;
        
    }
    
    return 0;
}
int main(int argc, const char * argv[]) {
    /*
    extern int global_val;
    std::cout << global_val<<std::endl; 如果用到 别的文件定义的变量，需要先声明一下，在使用
     */
//    simpleIO(); //输入输出
//    studyComments(); //注释的理解
//    controlStream();//for 和 while 循环
//    theNumberOfUserCin(); //读取数量不定的输入数据
//    countWhatYouCin(); //输入数字计数
//    SizeOfTypes();//数据类型
//    lvalueReference();//引用
//    pointer(); //指针
//    constantStudy();常量
//    typeAlias();
//    studyStruct();
    
    //studyString里面的方法
//    studyString();
//    studyVector();
//    studyArray();
    
    
//    expression里面的方法
//    studyExpression();
    
    //studyFunction里面的方法
//    studyFunction();
    
//studyClass的方法
//    studyClass();
    
//studyIO的方法
//    studyIO();

//study容器的方法
    studyOrderedContainer();
    return 0;//如果是-1的话这里会显示退出与255的错误代码
}



