//
//  studyIO.cpp
//  studyCPP
//
//  Created by slimdy on 2017/10/24.
//  Copyright © 2017年 slimdy. All rights reserved.
//

#include "studyIO.hpp"
//   ios::app：　　　以追加的方式打开文件
//　　ios::ate：　　　文件打开后定位到文件尾，ios:app就包含有此属性
//　　ios::binary：　以二进制方式打开文件，缺省的方式是文本方式。两种方式的区别见前文
//　　ios::in：　　　 文件以输入方式打开(文件数据输入到内存)
//　　ios::out：　　　文件以输出方式打开(内存数据输出到文件)
//　　ios::nocreate： 不建立文件，所以文件不存在时打开失败
//　　ios::noreplace：不覆盖文件，所以打开文件时如果文件存在失败
//　　ios::trunc：　　如果文件存在，把文件长度设为0

int studyI(){
    //打开文件
    string path = "/Users/slimdy/Desktop/好句.txt";
    ifstream fh = ifstream(path,ifstream::in); //读取文件
    if (!fh){
        cout << "文件不能打开"<<endl;
    }else{
        //        string str;
        //        while (fh >> str) { //遇到空格停止
        //
        //            cout << str << endl;
        //        }
        //        char line[1024];
        //        while (fh.getline(line, sizeof(line))){ //遇到换行符停止，这个是ifstream的getline
        //            cout << line << endl;
        //        }
        string str;
        while (std::getline(fh, str)) { //也是按行读取，但是这个是std的getline方法
            cout << str << endl;
        }
    }


    return 0;
}



int studyO(){
    string path = "/Users/slimdy/Desktop/test.txt";
    ofstream fh = ofstream(path,ofstream::out|ofstream::app);
    if (!fh.is_open()) {
        cout << "文件打开错误"<<endl;
        exit(1);
    }
    string str  = " i love you more than love me!" ;
    fh << str << endl;
    return 0;
}
int studyS(){
    string line,word;
    vector<PersonInfo> people;
    while (getline(cin,line)) {
        PersonInfo info;
        istringstream record(line);
        record >> info.name;
        while (record >> word) {
            info.phones.push_back(word);
            
        }
        people.push_back(info);
        
    }
    for(auto i = people.begin();i != people.end();++i){
        cout << (*i).name << endl;
    }
        
    return 0;
}
int studyIO(){     //标准读写
    //文件里读取数据
    //    studyI();  fileIO 文件读写
    //往文件里写
//    studyO();
    //往字符串里写  stringIO 内存读写
    studyS();
    return 0;
}
