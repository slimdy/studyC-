//
//  dataType.cpp
//  studyCPP
//
//  Created by slimdy on 2017/9/29.
//  Copyright © 2017年 slimdy. All rights reserved.
//

#include "dataType.hpp"

using namespace std;

int haha;
int global_val = 100;
int SizeOfTypes(){
    int a = 4;
    long b =4;
    long long c = 4;
    char d = 4;
    int *e = &a;
    float f = 4.0;
    double g = 4.0;
    bool h = true;
    short i = 4;
    std::cout << "int 是: " << sizeof(a)<< "\n"<< "long 是: " << sizeof(b)<< "\n"<< "long long 是: " << sizeof(c)<< "\n"<< "char 是: " << sizeof(d)<< "\n"<< "指针是: " << sizeof(e)<< "\n"<< "float 是: " << sizeof(f)<< "\n"<< "double 是: " << sizeof(g)<< "\n"<< "bool 是: " << sizeof(h)<< "\n" <<"short 是： "<<sizeof(i)<<"\n"<< std::endl;
    
    
    int a1 = 1;
    unsigned a2 = -1;
    std::cout<<"有符号的a1 = "<<a1<< std::endl;
    std::cout<<"无符号的a2 = "<<a2 << std::endl;
//练习
    unsigned u{10},u2 = 42; //初始化和赋值并不是一个概念，尤其是在c++中 初始化是开辟空间并且初始化一个新值，而复制时擦除旧的，赋予新的  这个花括号只能在初始化中使用
    std::cout << u2 - u<<std::endl; //32
    std::cout << u - u2<<std::endl; //4294967264
    int i1 = 10,i2 = 42;
    std::cout << i2 - i1<<std::endl; //32
    std::cout << i1 - i2<<std::endl; // -32
    std::cout << i1 - u<<std::endl; // 0
    std::cout << u - i1<<std::endl; // 0
    
    int hehe  ;
    std::cout<<"定义在函数外的 "<<haha<< std::endl; //函数外的变量 会自动初始化为0 而内部的则不一定
    std::cout<<"定义在函数内的 "<<hehe << std::endl; //在有些编译器的是undefined
    
    //声明与定义
    /*
     extern int val; //声明
     int val; 定义
     int val = 100 ； 定义
     extern int val = 100 ;定义
     变量的定义只能在一个文件里定义，如果其他文件需要用到它，则必须先声明，然后在使用
     */
    
    
    return 0;
}

/*
 引用分为左值引用和右值引用，一般的话说到引用都是左值引用
 */
int lvalueReference(){
    /* 引用的实质是给变量起个别名
     1.引用必须被初始化 也就是说不能直接用 int &ra; 这样会报错
     2.引用初始化时必须赋值是对象，不能直接是值  int &ra = 20； 这样会报错
     3.因为引用本身并不是对象，所以不能定义引用的引用
     4.引用的类型必须和被引用的对象一致
     */
    int  a = 100;
    int &ra = a;
    ra = 101; //引用的值变了 被引用的对象也会变化
    std::cout <<a<<std::endl; // 100
    std::cout <<ra<<std::endl; // 100
    
//练习
    int i ,&ri = i;
    i = 5;
    ri = 10;
    std::cout << i << " " << ri << std::endl; // 10 10
    //也就说明了引用和变量本身就指向同一个内存地址，你变我也变
    
    return 0;
}
/*
 指针：用来存放其他对象内存地址的对象  通俗来讲就是指针存储的是地址 ，它也是一个对象
 */

int pointer(){
    /*
     1. *出现在类型名后的时候，意味着 声明指针 int *p
     2. *出现在表达式，则是取值符号 *p = 0
     3. &出现在类型名后的时候，意味着 声明引用 int &r
     4. &出现在表达式，则意味着取地址符  &p
     */
    int a = 10;
    int *ap = &a;
    int *ap2 = 0; // 定义空指针  还可以用nullptr c++11新出现的
    std::cout << "a 的值 ： "<<a<< " 它的地址是： "<<ap<<std::endl;
//注意
    /*
     1. int i = 0 ; int *p = i  是不对的 ，不能把其他类型的对象，付给指针对象，指针只接受地址
     2. 未经初始化的指针是很危险的，最好是先定义对象，在定义指针，如果实在不清楚指针指向谁，就定义成空指针
     3. *p = 0  这个的意思是指针p 指向的对象的值 变成了0，p = 0 则表示 指针指向的对象变成了空，也就意味着没有指向任何对象
     4. 指针p 只要不是空指针，在判断的时候都为真
     5. void *p 便是空类型指针，意味着，这个指针可以存储任何对象的地址
     6.
     */
//测试
    int i = 42;
    int* pi = &i;
    std::cout << "i的值是： "<<i<<"  *pi : "<< *pi << std::endl;
    *pi = *pi * *pi;
    std::cout << "i的值是： "<<i<<"  *pi : "<< *pi << std::endl;
    
    return 0;
}
/*
 常量是不能修改的 ，所以它必须要进行初始化
 */
int constantStudy(){
    /*
     1.默认情况下，const 修饰的常量，仅在文件内有效，如果要多个文件都能访问，则在一个文件中extern 修饰符 修饰常量并定义，在其他文件中，extern 修饰声明，就可以使用了
     2.常量的引用  仅仅表示不能通过该引用修改常量 ，如果常量引用 引用的是普通变量，则不能通过引用去改变他的值，可以通过改变本身去改变他的值
     3.常量的指针， const int* p = 0
     4.常量表达式，是指在编译的时候   就能得到计算的结果的表达式
     */
    
//常量的引用
    const int i = 100;
    const int &ri = i;
//    ri = 101; 会报错 因为ri是常量的引用，不能通过修改常量引用来改变本身的值
    int j = 100;
    const int &rj = j;
//    rj = 101;会报错， 虽然j不是常量，可是 他的引用是常量引用，所以仅仅不能通过这个引用去改变他的值，但是可以通过改变他自己来改变引用。也就是说 const int &rj  其实本质上是对const 的引用，只要有const 就不能通过const 修饰的变量去改变这个值
    j = 101;
    std::cout << "j的值是： "<<j<<"  rj : "<< rj << std::endl;
    
    
//常量的指针
    //这里有两个概念 1。 常量指针： 指针本身也是对象，所以也可以被const修饰为常量指针，int *const p
                // 2. 指针指向常量对象： 这个意思就是普通指针 指向常量对象  const int *p = 常量
    int a = 100;
    int *const pa = &a; //常量指针的值不能改变，也就是说，常量指针将一直指向变量a的地址
//    pa = 0;//不能改变
    const int b =100;
    const int *pb = &b; // 这个是指向常量对象的指针
    pb = 0;// 可以改变 改变后不再指向常量b 变成了普通的指针
// 如果遇到const int *const p 这种指针的话 有顶层const 和底层const 来解释
    const int c = 100;
    const int *const pc =&c; // 右边的是顶层const 它是常量指针的修饰符  左边的底层const 是常量的修饰符，
    //如果只有左边的const（底层const） 则变量是可以修改的 ，如果是顶层的const，则是不能修改的
    
    
    
//常量表达式
    const int d = 1; //d就是常量表达式，在编译的时候 d的结果就是1
    const int e = d+1; //e也是常量表达式，编译的时候e 就等于d+1
    const int f = pointer();//这个并不是常量表达式， 因为他要在执行的时候，才会有结果
    //c++11 新规定 可以用constexpr来让编译器验证变量的值是不是常量表达式
    constexpr int g = e+100; //contexpr 不但验证 右边表达式是不是常量表达式 g也会被定义成常量
    return 0;
}
int typeAlias(){
//指针 常量类型 和别名
    typedef int* pstring;
    int a = 100;
    const pstring cstr = &a; //不能把这个式子看成 const int *cstr
    const pstring *ps  = &cstr; //int 指针的指针  这个理解的并不好
    std::cout << "cstr的值是： "<<cstr<<"  ps : "<< ps << std::endl;
    
//auto类型说明
    //auto会根据给的变量值 来判断 是什么类型的变量 ，auto定义的变量必须有初始值，如果要在一行里定义好几个变量，则这些变量的值的类型必须相同
    auto b = 1;
    std::cout << "b： "<<b<< std::endl;
    //b=3.14; //如果在前auto 已经定义了b的int  那么 后面b一致都是int型
    std::cout << "b： "<<b<< std::endl;
    
   // auto c = 0,*p = &c,d=3.14; 连续定义变量 auto第一个变量是什么类型的后面必须也是什么类型
//    auto d = 0,e = 3.14;//在一行之内必须数据类型一致
    
    
// decltype类型：是指根据表达式的返回值类型来定义变量的类型
    decltype(typeAlias()) c = 10;
    const int ci = 0,&cj = ci;
    decltype(ci) x = 10; //ci是整数型常量 所以x也是整数型常量
    decltype(cj) y = x; // cj是引用类型，收益以y就是引用类型
    //decltype(cj) z ;  //cj是引用类型，z是引用类型 引用必须初始化
    return 0;
    //
}
int studyStruct(){
    string sbin ="0-201-783245-x";
    Sales_data data1 = Sales_data(sbin,3,20);
    Sales_data data2 = Sales_data(sbin,3,25.5);//不知道为什么 这个编译器必须要在结构体里定义初始化方法
    if (data1.bookNo == data2.bookNo) {
        std::cout <<"totalNumber"<< data2.units_sold+data1.units_sold <<std::endl;
        std::cout << "totalPrice" << data1.revenue*data1.units_sold+data2.revenue*data2.units_sold <<std::endl;
    }else{
        std::cout << "these are not the same book"  <<std::endl;
    }
    
    
    

    return 0;
}
