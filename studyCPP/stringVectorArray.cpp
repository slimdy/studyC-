//
//  stringVectorArray.cpp
//  studyCPP
//
//  Created by slimdy on 2017/10/10.
//  Copyright © 2017年 slimdy. All rights reserved.
//

#include "stringVectorArray.hpp"
#include <iostream>
#include <vector>
using namespace std;
int studyString(){
//初始化
    string s1 ;
    //string s2 = s1; //这种也可以这样初始化
    string s2(s1);
    string s3 = "这是什么";
    string s4(10,'c'); //10个c组成的字符串
    
    
//从输如流中读取字符串
    string line1;
    string line2;
    
//    while (cin >> line1) {
//        cout << line1 <<endl;//空白符为结束符
//    }
    
//    while (getline(cin, line2)) {//换行符为结束符，在输出的时候丢弃了换行符
//        cout << line2 << endl;
//    }

    
//empty和size操作
    cout << " s3 is empty ?" << s3.empty() <<endl; //为空返回真，不为空返回假
    cout << " s2 is empty ?" << s2.empty() <<endl;
    
    
    cout << "s3 size :" << s3.size() <<endl;
    cout << "s2 size :" << s2.size() <<endl;
    
    string s5 = "hello ";
    string s6 = "world!!!!";
//    string s7 = " wo " + " ai " +" ni "; //加号两边必须有一是string 才会把字面值转换成string类型
    string s7 = s5 + " wo " + "ai" +" ni ";
    cout << s7 << endl;
    
    for (auto c :s6){
        cout << c << endl;
    }
    
    decltype(s6.size()) punct_cnt = 0; //在这里用int是可以的，用这个的目的主要是熟悉一下decltyoe的用法
    for (char c : s6){ //这里用char也是可以的 但是本人认为用auto让计算机去算还是比较好的
        if (ispunct(c)){
            ++punct_cnt;
        }
    }
    cout << punct_cnt << " 个标点在字符串： " << s6 << endl;
    
    for (auto &c :s6){ //这里要使用引用，因为c  只是个临时变量，它被拿出来后，它的变换无法影响到原字符串，所以要把每个元素的引用定义为c 这样修改每个c就会影响到原字符串。
        c = toupper(c);
    }
    cout << s6 << endl;
    
    
    string s8  = s5 + " world";
    if (!s8.empty()){
        s8[0] = toupper(s8[0]);
        for (decltype(s8.size()) index = 0; index < s8.size(); ++index) {
            if (isspace(s8[index])){
                s8[index + 1] = toupper(s8[index+1]);
            }
        }
    }
    cout << s8 << endl;
    return 0;
    
}

int studyVector(){
//vector是一个可以包含对象的容器
//初始化
    vector<int> iv1;
    vector<int> iv2 = iv1;//等价于 vector<int> iv2(iv1)
    vector<int> iv3(10);
    vector<int> iv4(10,-1);
    vector<int> iv5 = {1,22,1,23};//等价于 vector<int>iv5 {1,22,1,23}
    //注意
    vector<int> iv6 {10};//花括号是：列表初始化，表示iv6中只有一个对象 10，只有当花括号中的元素不是初始化元素事，会尝试按照圆括号来表示元素个数
    vector<string> sv1{10};//因为10不是string类型的所以花括号不能用于列表初始化，所以他就退而求其次，把10当成元素个数
    vector<int> iv7 (10);//原括号是：表示iv7中有多少个元素。
    
    
//给vector添加元素
    for (int i = 0 ; i <= 10; ++i) {
        iv1.push_back(i);
    }
    //vector也有size和empty方法 也可以用下标来查找元素
    for (auto &i :iv1) {
        i *= i;
    }
    for (auto i : iv1){
        cout <<  i <<"  "<< endl;
    }
//小例子
    
    vector<unsigned> scores (11,0);
    unsigned grade;
    while (cin >> grade) {
        if (grade<=100){
            ++scores[grade/10];
        }
    }
    for (auto i : scores){
        cout <<  i <<"  "<< endl;
    }

//迭代器:类似于指针，也是指向容器中某个元素
    string text = "hello world";
    auto a = text.begin();
    auto b = text.end();
    std::cout << "begin : " << *a <<std::endl; //a就是text第一个字符的迭代器 *a表示取这个迭代器的值 是h
    std::cout << "end : " << *b <<std::endl; //end 是最后一个迭代器，他表示的是这个text的最后一个字符再往后一位
    //如果字符串为空，则begin和end都是同一个迭代器。
    
    if (text.begin() != text.end()) {
        for (auto it = text.begin(); it != text.end() && !isspace(*it); ++it) {
            *it = toupper(*it);
        }
    }
    std::cout << "text : " << text <<std::endl;
    //迭代器的加法是表示移动位置
//二分搜索 :从中间开始搜索,如果该元素大于中间元素，则抛弃前半部分，只在后面搜索，反之亦然。
    // 伪代码
//    auto beg = text.begin();
//    auto end = text.end();
//    auto mid = beg +(end-beg)/2;
//    char c = 'e';
//    while (mid!=end && *mid != c) {
//        if (c < *mid) {
//            end = mid ;
//        }else{
//            beg = mid+1;
//        }
//        mid = beg+(end-beg)/2;
//    }
    
    return 0;
}

int studyArray(){
    
//数组的初始化(静态数组)在栈上开辟内存，动态数组，在堆上开辟内存 new malloc
    //数组的维度必须是常量表达式 :字面值或者是constexp修饰的表达式,虽然有的编译器是支持变量作为维度的但是，为了可移植性还是要遵循规则
    int a = 3;
    int arr[3] = {1,2,3}; //会默认初始化 即三个0
    constexpr int b = 3;
    //int arr2[a] = {1,2,3} ; //会报错，因为a是变量 但是可以声明，这个是编译器的可扩展性
    string arr2[b] = {"hello","world","oh"}; //如果初始化的值和维度不符，大于维度会报错，小于会默认初始化
    int *arr3[b] ;//含有3个整形指针的数组
    //字符数组稍有特殊 ：不但可以用大括号的方式进行初始化 还可以直接用字符串字面值
    char arr4[7]="sunset";//会报错 因为字面值的最后一个字符是空白字符所以如果六个字母的单词必须存入7位的数组中
    char arr5[3] = {'C','+','+'};//这种初始化方式就没有空白符 /0
//    int arr6[] = arr; //不允许用一个数组来初始化另一个数组
    int arr7[3] = {0,0,0};
//    arr7 = arr;//不能把一个数组赋值给另一个数组,有的编译器支持赋值，但是标准是不行的，会影响可移植性
    

//一些复杂的数组声明和定义
    int *ptr[10]; //含有10个整形指针的数组
    //int &refs[10]; //错误,不存在引用的数组，因为数组是用来存储对象的，而引用不是对象，所有不存在
    int (*parray)[3] = &arr; //从内向外理解，*parray是个指针，[3]表示是指向3个元素数组的指针，左边的int 代表指向含有三个元素的整形数组的指针
    int (&arrRef)[3] = arr;//和上面的那个同理，arrRef是对3维度的整形数组的引用
    
    
//访问数组的元素
    for (auto i : arr2) {
        cout << i << endl; //循环
    }
    cout << arr2[1]<<endl; //下标
    
    //数组有个特性 ： 用到数组名称的地方，编译器会把他转换成首元素的指针
    string *p1 =arr2;
    cout << p1<<endl; //等价于 string* p1 = &arr2[0]
    //再用另一个方面进行演示
    int arr8[] = {0,1,2,3,4,5,6,7,8,9};
    auto  arr9(arr8);
    cout << arr9 << endl;//auto 自动判断是个指针
    //但是当用decltype的时候，就不会把arr8转换成首元素的指针
    decltype(arr8) arr10 = {};
    for (auto i : arr10) {
        cout << i << endl; //循环
    }
    
    //数组的指针也是迭代器
    string *p2 = ++p1;
    cout<<*p2 <<endl; //指针加一表示向后移一位
    //和vector是一样的，如果想要迭代所有数组里的内容，也需要首元素的迭代器，和尾元素下一位置的迭代器
    string *bp = arr2;
    string *ep = &arr2[3];
    for (string *i = arr2; i != ep; ++i) {
        cout << *i << endl;
    }
    //上面的找到首尾迭代器的方法很麻烦
    
    bp = begin(arr2);
    ep = end(arr2);
    cout << "arr2的元素个数 ： " << bp-ep<<endl;
    for (string *i = arr2; i != ep; ++i) {
        cout << *i << endl;
    }
//    string *p3 = p1+10;超出范围的指针不知道会指向何处
//     cout << *p3 << endl;
    
    int ia[] = {0,2,4,6,8};
    int last1 = *(ia+4);
    cout<< last1 <<endl;
    int last2 = *ia +4;
    cout<< last2 << endl;
    
    
//数组下标和指针下标
    string s1 = arr2[1];//这个的原理是arr2先转换成首元素的指针 然后在arr2[1] 就相当于首元素的指针+1在解引用所得的值
    //上面的式子就相当于int *p =arr2; string s1 = *(p+1)
    string* p3 = &arr2[1];
    string s2 = p3[1]; //相当于*(p3+1)
    string s3 = p3[-1];//相当于*(p3-1)
    std::cout << "s1" << s1 <<std::endl;
    std::cout << "s2" << s2 <<std::endl;
    std::cout << "s3" << s3 <<std::endl;

    
//多维数组
    int da[3][4] = {
        {
            0,1,2,3
        },{
            4,5,6,7
        },{
            8,9,10,11
        }
    };
    cout<<da<<endl;
    cout<<da[0][2]<<endl;
    int (*dp)[4]= da; //数组指针，指向含义有四个整形元素的数组
    //用指针的方式循环数组
    for (auto p = da;p != da+3;++p) { //da取首元素地址给指针p，在da+3次循环 也就是3次循环
        for (auto q = *p; q != *p+4; ++q) { //指针p解引用 为内层第一个元素他也是数组，所以会把内层数组的首元素地址赋给指针q，*p本身就是内层第一个元素的地址，所以+4就表示这个地址的后面四个，循环四次
            cout<<*q<<endl;
            
        }
    }
    //用迭代器的方式循环
    for (auto p = begin(da); p != end(da); ++p) {
        for (auto q = begin(*p); q != end(*p);++q){
            cout<<*q<<endl;
        }
    }
    
    return  0;
}
