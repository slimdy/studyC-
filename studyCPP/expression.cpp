//
//  expression.cpp
//  studyCPP
//
//  Created by slimdy on 2017/10/13.
//  Copyright © 2017年 slimdy. All rights reserved.
//

#include "expression.hpp"
#include <iostream>
#include <vector>
using namespace std;
int studyExpression(){
//自增 的前置后置
    int i = 0;
    int j;
    j = i++; //先给值在加
    std::cout << " i++ =  " << j <<std::endl;
    i = 0;
    j = ++i; //先加再给之
    std::cout << " ++i =  " << j <<std::endl;
    
    string s = "hello";
    auto sb = s.begin();
    while (sb != s.end() && !isspace(*sb)) {
        cout << *sb++<<endl; // *运算的优先级低于 ++运算  所以显示迭代器++ 然后在取值 和 *(sb++) 是一样的
                            //  *运算符优先级也低于.运算符
    }
    sb = s.begin();
    while (sb != s.end() && !isspace(*sb)) {
        *sb = toupper(*sb); 
        ++sb;
    }
    std::cout << "s =  " << s <<std::endl;
    
    
//三元运算符
    int grade = 91;
    string finalGrade = (grade > 90)?"highGrade Pass":(grade > 60) ? "pass":"Failed";
    cout<<"final Grade :  " << finalGrade <<endl;
    


    
//位运算
    //班级里有30个学生，其中第27个学生成绩合格，用位运算表示
    unsigned long q = 0;
    unsigned long p = 1;
    cout <<  sizeof(q) <<endl;
    unsigned long s27 = p << 27;
    cout <<  s27 <<endl;
    cout <<   (s27 | q)  << endl;
    
    

    
//sizeof
    //sizeof返回的是该表达式结果类型所占的空间大小(按位)
    int sizeA = 10;
    int sizeB = 1000;
    int *pA = &sizeA;
    string Sizec = "sdsasd";
    string SizeD = "我爱你你爱我么";
    int SizeE[] = {1,2,3,4,5,6,7,8,9};
    vector<int> SizeF = {12,2,32,3,23,222,10};
    cout << "int sizeA :" << sizeof(sizeA) <<endl; //4
    cout << "int sizeB :" << sizeof(sizeB) <<endl; //4
    cout << "int * PA :" << sizeof(pA) <<endl; // 8
    cout << "int sizeC :" << sizeof(Sizec) <<endl; //24
    cout << "int sizeD :" << sizeof(SizeD) <<endl; //24
    cout << "int sizeE :" << sizeof(SizeE) <<endl; //36
    cout << "int sizeF :" << sizeof(SizeF) <<endl; //24
    //除了数组 剩下的数据类型只返回固定的大小，而数组会返回每个元素的大小的总和,通过这个特性可以计算数组元素的个数
    cout << "sizeE的元素个数 ： "<< sizeof(SizeE)/sizeof(*SizeE) <<endl; //9
//例题
    int x[10];
    int *px = x;
    cout << sizeof(x) / sizeof(*x)<<endl; //数组的个数 10
    cout << sizeof(px) / sizeof(*px) << endl; //指针所占的位数 除以int所占的位数 2
    
    
//类型转换
    //隐示类型转换
    int la = 3.1415; //编译器自动转换为int型
    //强制类型转换
    double la1 = static_cast<double>(la); //强制把除了常量的其他类型转换成别的类型
    const char *pc = nullptr ;
    char *pp = const_cast<char *>(pc); //转换常量到非常量
    //旧式的强制类型转换
    int la2 = 10;
    double la3 = double(la2);//或者用（double）la2
    //无论在何时尽量不要使用，强制类型转换
    
    
//控制语句  goto
    int hehe = 1;
    goto begin; //跳转到标签语句
    begin: //标签语句可以任意起名
    std::cout << "hehe : " << hehe << std::endl;
    haha:
    hehe +=1;
    std::cout << "hehe : " << hehe <<std::endl;
    
    int h=10 ,l,chu;
    cin >>l;
    try {
        if(l == 0){
            throw logic_error("除数不能为0");
        }
        chu = h/l;
        cout << chu <<endl;
    } catch (logic_error error) {
        cout << "输入错误 :" << error.what() <<endl;
    }
    
    return 0;
    
}
