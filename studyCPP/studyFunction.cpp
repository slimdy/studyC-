//
//  studyFunction.cpp
//  studyCPP
//
//  Created by slimdy on 2017/10/18.
//  Copyright © 2017年 slimdy. All rights reserved.
//

#include "studyFunction.hpp"

using namespace std;
void sayHello(const string &str){ //首先这里为什么要用引用：因为如果字符串如何特别法 用拷贝的方法是很耗费性能的，如果在函数内内部并不修改字符串内容的话 建议用引用。那为什么用常量引用，因为常量引用可以接收非常量或者常量引用，他的覆盖面更加宽.而且容易让里面的操作修改引用的对象
    cout << str << endl;
}
const string & shorterString(const string &s1,const string &s2){
    //传入的参数是const的引用，返回的也是引用，函数不能把局部变量的引用传出去，因为函数结束局部变量就销毁了。只能把参数的引用传出去
    return s1.size() <= s2.size() ? s1: s2;
}

//传入数组指针返回数组指针
int (*change(int a[5]))[5]{ //这是函数返回数组指针最麻烦的一种形式，type (*fucntion(argvs))[size]
    *(a+1) = 32;
    return (int(*)[5])a; //a是数组的首元素指针 将它转换为数组的指针
}
//c++ 11 最新的方法
auto change1(int a[5])->int(*)[5]{ //大大的简化了上面的那种形式，让人更容易理解
    *(a+1) = 42;
    return (int(*)[5])a;
}

//函数的指针
int sum(int a,int b){
    
    return a+b;
}
//函数指针作为参数
int newSum(int a,int b,decltype(&sum) pf){ //函数指针作为参数是 函数指针声明的方式是 type(*p)(形参),用decltype来自己判断sum指针的形式也是可以的
    a +=1;
    b +=1;
    return  (*pf)(a,b);
}
//返回值为函数指针
int (*sumAll(void))(int,int){
    int(*ps)(int,int) = &sum; //也可以返回sum
    return ps;
}
//等价写法 和上面的一样
auto sumAll1(void)->int(*)(int,int){
    return &sum;
}
int studyFunction(){
    string str = "sdassdsadsasss";
    string &lala = str;
    sayHello(lala);
    sayHello("sdsasdssssssdsdsdsd");// 这里认为“” 这个字符串是常量 ，而sayhello函数 参数接收为普通引用，所以会报错
    //普通引用 无法接收常量引用 而常量引用可以接收普通引用
    int a[] = {1,2,3,4,5};
    
    
//    int (*b)[5] = change(a);
    int (*b)[5] = change1(a);
    for (auto i = begin(*b); i != end(*b); ++i) {
        cout << *i << endl;
    }
    
//sum函数的指针
    int(*pfunc)(int,int) = sum; //&sum也可以，他们是等价的
    cout << (*pfunc)(1,3) << endl; //不用*也可以
    
//sum函数指针作为参数
    cout << newSum(3,5, pfunc) << endl;
    
//sum函数作为返回值
    cout<<sumAll1()(1,2)<<endl; //sumAll的返回值是sum函数的指针
    
//返回sum的指针
    return 0;
}

