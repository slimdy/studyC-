//
//  studyClass.cpp
//  studyCPP
//
//  Created by slimdy on 2017/10/19.
//  Copyright © 2017年 slimdy. All rights reserved.
//

#include "studyClass.hpp"
const string Animal::liveTo = "earth";
int studyClass(){
    string name = "张三";
    string gender = "女";
    Animal animal = Animal("人类",2,false);
    Person p1 = Person(name);
    p1.getPersonInfo(animal);
    Person p2 = Person();
    p2.getPersonInfo(animal);
    Person p3 = Person(name,gender,28);
    p3.getPersonInfo(animal);
    p3.fixTheInfo().getPersonInfo(animal);
    saySomething(p3, animal);
    return 0;
}
Person::Person(string &name){
    this->name = name;
}
void Person:: getPersonInfo(const Animal &animal) const{
    animal.getAnimalInfo();
    cout << this->name <<"的年龄是 "<<this->age<<"岁,性别是"<<this->gender<<endl;
}
void Animal::getAnimalInfo() const{
    string fly = this->isfly ?"会飞":"不会飞";
    cout << "该动物是： "<< this->name << ",有" << this->legs <<"条腿，" << fly << ",住在"<<Animal::liveTo << ",今年是"<<Animal::liveToday<<endl;
}
void saySomething(const Person &person,const Animal &animal){
    string fly = animal.isfly ? "can":"can't";
    cout << " my name is " << person.name <<","<<person.gender<< ", I am "<<person.age << ","<< "I have " << animal.legs << " legs and I "<<fly <<" fly ."<<endl;
}
