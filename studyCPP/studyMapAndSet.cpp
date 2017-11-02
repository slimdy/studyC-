//
//  studyMapAndSet.cpp
//  studyCPP
//
//  Created by slimdy on 2017/11/2.
//  Copyright © 2017年 slimdy. All rights reserved.
//

#include "studyMapAndSet.hpp"
void tansform_text(){
    map<string, string> dictionary ;
    dictionary["k"] = "Okey";
    dictionary["y"] = "why";
    dictionary["r"] = "are";
    dictionary["u"] = "you";
    dictionary["pic"] = "picture";
    dictionary["thk"] = "thanks!";
    string text = " where r u ? y dont u send me a pic ? k ? thk ";
    vector<string> textVec;
    string str;
    istringstream is(text); //流对象
    while (is >> str) {
        textVec.push_back(str);
    }
    for (auto &i : textVec) {
        if (dictionary.find(i) !=  dictionary.end()) { //如何判断key是否在map中
            i = dictionary[i];
        }
    }
    string newText;
    for (auto i : textVec){
        newText += " "+i ;
    }
    cout << newText << endl;
}
int studyMap(){
//map是一种关联数组，是有序的容器 ,它存放的是key-value 形式的数据 multimap 是可以允许重复的字典
    //但是，要知道的是map和set 都是按照升序的方式排布的，在内存中却不是连续的，所以迭代器，不能加减
    //返回的是该添加元素的迭代器和是否添加成功的布尔值
    map<string,size_t> word_count; //vector可以重复保存数据，而map不能，但是multimap是可以的
    string word;
    while (cin >> word) {
        ++word_count[word];
    }
    
    for (const auto &w : word_count) {
        cout << w.first << " 出现了 " << w.second << ((w.second >1) ? " times" : " time") << endl;
    }
    /* map<string,size_t> :: value_type  是pair(string,size_t)类型
       map<string,size_t> :: key_type   是string类型 是const的
       map<string,size_t> :: mapped_type 是size_t类型
     */
// 添加元素
    word_count.insert({"woaininiaiwome",2}); //返回的是该添加元素的迭代器和是否添加成功的布尔值
    word_count.insert(make_pair("zhoumoniyoukongme", 3));
    word_count.insert(pair<string, size_t>("iloveyoumorethanloveme",5));
    word_count.insert(map<string, size_t>::value_type("ilookingformycouterpart",23));
// 其他添加操作
    auto a = word_count.emplace("hehe",1);
    cout << a.first->first << a.first->second << a.second << endl;
    a  = word_count.emplace("hehe",3); //emplace 是用构造函数传参的形式构造新的元素pair，返回的是该添加元素的迭代器和是否添加成功的布尔值
    cout << a.first->first << a.first->second << a.second << endl;

    //c.insert(b,e) 添加b和e迭代器之间的pair对象
    //c.insert(p,v) 在p迭代器的位置搜索新迭代器添加的位置
// 删除操作
    word_count.erase(word_count.begin());//返回值是void
    word_count.erase("woaininiaiwome");//返回值是删除元素的数量
    word_count.erase(word_count.begin(),word_count.end());//返回 word_count.end

// 访问元素之下标操作
    cout << word_count["hehe"] << endl; //没有就添加
    cout << word_count.at("hehe") << endl;//没有报错
    word_count["ifnckyoumom"] = 23;//有了就改变，没有就创建
// 访问元素之方法操作
    //c.find(k) //返回关键字为k的迭代器,若k不存在，则返回尾后迭代器
    //c.count(k) //如果是可重复的则返回数量,如果不可重复的则和find一样
    
    map<int, int> test1;
    for (int i = 10; i < 20; ++i) {
        test1[i] = i-10;
    }
    cout << test1.lower_bound(10)->first<<":"<<test1.lower_bound(10)->second << endl; //第一个关键字出现的位置
    cout << test1.upper_bound(10)->first<<":"<<test1.upper_bound(10)->second << endl; //最后一次关键字元素后一位的位置  如果这两个返回的元素迭代器相等，则表明元素并不在这个容器中.可以用它来判断这个元素是否存在
    cout << test1.equal_range(10).first->first << ":" << test1.equal_range(10).first->second << endl;
    cout << test1.equal_range(10).second->first << ":" << test1.equal_range(10).second->second << endl;
//    equal_range 这个功能 就是返回lower 和upper的返回值的pair
    
    
    return 0;
    
}
int studySet(){
    cout << "与上面的map的操作一致" << endl;
    tansform_text();
    return 0;
}
