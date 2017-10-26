//
//  studyClass.hpp
//  studyCPP
//
//  Created by slimdy on 2017/10/19.
//  Copyright © 2017年 slimdy. All rights reserved.
//

#ifndef studyClass_hpp
#define studyClass_hpp

#include <stdio.h>
#include <iostream>
using namespace std;
int studyClass();
struct Person;
class Animal{
    
    friend class Person; //友元是Person类 也就意味着Person 可以通过对象调用到private修饰的成员属性和方法
    friend void saySomething(const Person &,const Animal &); //友元是函数，也就意味着函数可以通过对象调用prvate修饰三维成员属性和方法
public:
    typedef string  str; //可以在类内给较长的类型定义别名
    using lfint = int; //两种都可以
private:
    str name ; //类初始化成员变量是会按照变量定义的顺序初始化
    lfint legs = 4;
    bool isfly  = false;
//    static string liveTo = "earth"; 不能这样初始化
    static const string liveTo;
    static const int liveToday = 2017; //静态常量可以直接初始化
    void getAnimalInfo() const;
public:
    Animal() = default;
    Animal(const string &name,int legs,bool isfly):name(name),legs(legs),isfly(isfly){}
    Animal(const string &name):Animal(name,4,false){}//委托构造函数 她是借用上面的构造函数定义的
    
};

struct Person{
    friend void saySomething(const Person &,const Animal &);
private:
    string name;
    mutable int age = 0; //age变成可变的成员变量 age可以再const 修饰的函数内更改
    mutable string gender = "男";
public:
    //定义在类内部的函数是隐示内联的
    string getName() const { //这里const 指的是 this 是const的
        string newName = "slimdy";
        return name;
    }
    //而在类外的方法 需要显示声明为内联函数
    inline void getPersonInfo(const Animal &) const; //类外实现
    //构造函数  重载的特性 ：后面的是将参数赋值给类成员变量
    Person() = default; //默认的构造函数
    Person(string &name,string &gender):name(name),gender(gender){} //将name赋值给类的name成员变量
    Person(string &name,string &gender,int age):name(name),gender(gender),age(age){}
    Person(string &name); //这个是在类外实现了
    Person& fixTheInfo() { // 这里返回引用是 直接返回本对象，如果返回对象则会在赋值的时候拷贝。
        age = 18;
        gender = "帅哥";
        return *this;
    }
};
void saySomething(const Person &,const Animal &);


#endif /* studyClass_hpp */
