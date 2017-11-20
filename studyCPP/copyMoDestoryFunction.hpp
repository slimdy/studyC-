//
//  copyMoDestoryFunction.hpp
//  studyCPP
//
//  Created by slimdy on 2017/11/17.
//  Copyright © 2017年 slimdy. All rights reserved.
//

#ifndef copyMoDestoryFunction_hpp
#define copyMoDestoryFunction_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
void studyCopyMoveDestoryFunc();
class PersonOne{
public:
    PersonOne(const string& name, const string& sex,const string& national,int age):
    name(name),
    sex(sex),
    national(national),
    age(age),
    legs(2),
    sick(new int(10))
    {
        
        cout << " 构造函数" <<endl;
    }
    
    PersonOne(const PersonOne& person)://copy构造函数如果是delete 说明 这个类的对象在不能拷贝
    name(person.name),
    sex(person.sex),
    national(person.national),
    age(person.age),
    legs(person.legs),
    sick(new int(*person.sick))
    {cout << " 拷贝构造函数"<<endl;}
    
    PersonOne& operator = (const PersonOne& person){ //赋值如果是delete  就意思是这个类创建的对象不能赋值
        name = person.name;
        sex = person.sex;
        national = person.national;
        legs  = person.legs;
        age = person.age;
        delete sick; // 释放原来对象中旧的sick指针，在赋予新的指针
        sick = new int(*person.sick);
        cout << "我是赋值操作符"<< endl;
        return  *this;
    }
    
    ~PersonOne(){  //析构函数不能是delete
        cout << "我是析构函数" <<endl;
      delete sick;
    }
    
private:
    int age;
    int legs;
    void say(string something);
    string name;
    string sex;
    string national;
    int *sick ;
   
};
//类似值的类（赋值或者拷贝后 新的对象和旧的对象，是两个无关联对象。修改其中一个对了另一没有影响）
class HasPrt{
public:
    HasPrt(const string &s = string()):
    ps(new string(s)),i(0){
        
    }
    HasPrt(const HasPrt& p):
    ps(new string(*p.ps)),i(p.i){
        
    }
    HasPrt& operator = (const HasPrt & hp){
        auto newp = new string(*hp.ps); //不能直接把 new string(*hp.ps) 赋值给ps 因为 如果hp 和*this 是同一个对象，在此之前 我们已经将ps delete掉了。 new string(*hp.ps) 会出现一个错误 ，因为*hp.ps已经delete了。所以先要把它报错在newp里面 这样即使他们是同样一个对象，也可以避免错误
        delete ps;
        ps = newp;
        i = hp.i;
        return *this;
    }
    ~HasPrt(){
        delete ps;
    }
private:
    std::string *ps;
    int i ;
};
//类似指针的对象(自定义引用计数)
class HasPrtCustomCounter{
public:

    HasPrtCustomCounter(const string &s = string()):
    ps(new string(s)),i(0),use(new size_t(1)){
        cout << "构造函数" << endl;
        cout << "引用计数是 :" << *use << endl;
    }
    HasPrtCustomCounter(const HasPrtCustomCounter& hpcc):
    ps(hpcc.ps),
    i(hpcc.i),
    use(hpcc.use){
        cout << "拷贝函数" << endl;
        ++*use;
        cout << "引用计数是 :" << *use << endl;
    }
    HasPrtCustomCounter& operator =(const HasPrtCustomCounter &hpcc) {
        cout << "赋值函数" << endl;
        ++*hpcc.use;
        cout << "赋值对象的引用计数是 :" << *hpcc.use << endl;
        if (--*use == 0) {
            delete ps;
            delete use;
        }
        ps = hpcc.ps;
        i = hpcc.i;
        use = hpcc.use;
        cout << "被赋值对象引用计数是 :" << *use << endl;
        return *this;
    }
    ~HasPrtCustomCounter(){
        cout << "析构函数" << endl;
        auto i = --*use;
        cout << "引用计数是 :" << i << endl;
        if (i == 0) {
            delete ps;
            delete use;
        }
    }
private:
    std::string *ps;
    int i;
    size_t *use;
};
// 类似于指针行为的类
class HasPrtSmartPointer{
public:
    HasPrtSmartPointer(const string &s = string()):
    i(0),ps(shared_ptr<string>(new string(s))){

    }
    HasPrtSmartPointer(const HasPrtSmartPointer& hpsp):
    ps(hpsp.ps),
    i(hpsp.i){

    }
    HasPrtSmartPointer& operator = (const HasPrtSmartPointer &hpsp){
        ps = hpsp.ps;
        i = hpsp.i;
        return *this;
    }
    ~HasPrtSmartPointer(){

    }
    shared_ptr<string> ps ;
private:
    
    int i ;
    
};
#endif /* copyMoDestoryFunction_hpp */
