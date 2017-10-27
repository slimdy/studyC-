//
//  studyContainer.cpp
//  studyCPP
//
//  Created by slimdy on 2017/10/25.
//  Copyright © 2017年 slimdy. All rights reserved.
//
//顺序容器类型
/*vector 可变大小数组，支持快速随机访问，在头部和中间插入元素的速度慢
 *deque  双端队列  支持快速随机访问，在头尾插入元素速度快
 *list   双向链表  支持双向顺序访问 在list中任何位置进行插入和删除都很快
 *forward_list  单向顺序访问，在任何位置插入否很快
 *array 固定大小数组 支持随机访问 不能添加或删除元素
 */
#include "studyContainer.hpp"
int studyOrderedContainer(){
//容器包含的类型别名
    vector<int> vec1= {1,2,3,4,5};
    vector<int>::iterator beginIter = vec1.begin(); //迭代器
    vector<int>::const_iterator cbeginIter = vec1.cbegin(); //常量迭代器
    vector<int>::size_type length = vec1.size(); //元素个数类型
    vector<int>::difference_type distance = vec1.end() - vec1.begin(); //元素个数类型
    vector<int>::value_type element = vec1[1]; //元素类型
    cout << typeid(element).name() << endl;
//构造函数 （初始化）
    vector<int> vec2; //默认构造函数 构造空的容器
    vector<int> vec3(vec1);//将v1拷贝给v3
    vector<int> vec4(vec3.begin(),vec3.end());//迭代器范围之内的元素
    vector<int> vec5(5,1); //5个1
    
// 赋值
    vec2 = vec1;
    vec3 = {2,4,6,8};
    int *p = &(vec2[1]);
    cout << *p << endl;
    vec2.swap(vec3); //交换两个容器里面的元素  swap(vec2,vec3)
    cout << *p << endl; //交换完后指针没改变
    for(int i=0; i<vec3.size(); i++) //forword 不支持size()
    {
        cout<<vec3[i]<<endl;
    }
    bool isEmpty = vec2.empty(); //如果有元素则返回false ，没有则返回true
    list<int> list1 = {1,2,3,4,5};
    vec5.assign(list1.begin(), list1.end()); //不同类型的list和vector可以用assian 赋值
    list1.assign(10, 1);//还有一种重载的assign 是 10个1

//注意 Array 和内置数组 a[]的区别
    int a[5] = {1,2,3,4,5};
    int b[5];
   //int b[5] = a;//因为a代表的是a数组的首元素的指针，内置的数组不能拷贝和赋值(初始化列外)
    
    array<int, 5> arr1 = {1,2,3,4,5};
    array<int , 5> arr2 = arr1; //array类型就可以赋值和拷贝  它的大小也是它的一部分，
    array<int, 5> arr3;
    arr3 = arr2;
    
//向容器里添加元素
    /* forward_list 不支持push_back he emplace_back
     * vector 不支持push_front 和 emplace_front
     * push_back emplace_back 在c的尾部创建一个值
     * push_front emplace_front 在头部创建一个值
     * insert（p,t） 在迭代器p之前添加t 返回新添加元素的迭代器
     * insert(p,n,t) 在迭代器p之前添加那个值为t的元素，返回指向第一个新添加的元素的迭代器
     * insert (p ,b ,e) 在迭代器p之前添加其他容器迭代器b到e之前的元素，返回指向第一个新添加的元素的迭代器
     * insert(p,il（列表）) 在迭代器p之前添加il列表里的所有固定元素。返回第一个添加元素的迭代器
     * 向vector string deque 插入元素 会使迭代器，指针，引用失效
     * emplace_front 添加到前面 传入的不在是一个对象，传入的是该元素构造函数的参数
     * emplace_back 添加到后面 传入的不在是一个对象，传入的是该元素构造函数的参数
     * emplace(iter,args) 添加到迭代器之前 传入的是构造函数的参数
     *
     */
    //push_back 除了array和forward_list以外，其他的容器都可以使用
    //push_front 除了vector array以外，其他容器都可以使用
    //insert 所有都支持除了array 但是forward_list的方法比较特殊
//访问容器中的元素
    /*c.begin() 获得首元素迭代器 *(c.begin()) 获得第一个元素的
     *c.end() 原理同上
     *c.front() 返回首元素的引用 改变这个就是改变原数组
     *c.back() 同上 不适用与forwardlist
     * at 和 下标 c.at(n) 和 c[n] 返回下标为n的元素,如果下标越界  c[n] 会出现未定义的问题，而at会抛出outofrange
       只适用于 vector string deque array 因为他们是可以随机访问的容器
     */
    cout << "--------------------" << endl;
    cout << vec2.back()<<endl;
    auto &slimdy = vec2.back(); //返回的是引用
    auto slimdy2 = vec2.back(); //返回的是对象的拷贝
    auto slimdy3 = *(vec2.end()-1); //返回的是对象的拷贝
    cout << slimdy3 <<endl;
    auto &slimdy4 = vec2.at(3); //返回的是对象的引用
    slimdy2 = 13;
    cout << vec2.back()<<endl;
    slimdy = 13;
    cout << vec2.back()<<endl;
    slimdy3 = 26;
    cout << vec2.back()<<endl;
    slimdy4 = 26;
    cout << vec2.back()<<endl;
//删除容器中的元素
    //所有删除的方法都不适用于array
    /* c.pop_back 删除c的尾元素 若c为空 结果未定义 forward_list不支持
     * c.pop_front 删除c的首元素 vector和string 不支持
     * c.earse(p) 删除迭代器p所在的元素 返回被删除的元素之后元素的迭代器
     * c.earse(b,e) 删除迭代器b和e之间的元素，若 e是尾部迭代器，则还是返回尾部迭代器
     * c.clear() 删除所有的元素
     * 删除元素会引起原来的迭代器，引用，指针失效。
     */
     //forward  特殊的插入器 迭代器之后添加数据   特殊的删除器 删除p之后的元素
    
//改变容器的大小
    //c.resize(n)  调整c的大小 为n  增加的元素，默认初始化 缩小的会被丢弃
    //c.resize(n,t) 调整c的大小为n  增加的元素，初始化为t 缩小的会被丢弃
    
//什么时候会元素的迭代器，指针，引用会失效
    /*1.添加元素
     如果容器是vetor string的时候 会失效.
     如果容器是deque给首尾添加的时候 迭代器会失效 指针和引用不会失效 如果给中间添加的时候，三个都会失效
     如果容器是list forwardlist 不会失效
     *2.删除元素
     如果容器是list forwardlist 不会失效
     如果容器是deque 如果删除的位置是除了首尾之外的，则会失效，如果是删除的尾部，则尾喉迭代器失效，其他没影响。如果是首元素被删除，则没有影响
     如果是 vector string 总是会失效的
     */
//容器内存分配空间
    vector<int> vec6;
//    vec6.shrink_to_fit(); 这个的含义是不需要vec6的capacity工作 不需要多余的保留空间
    vec6.reserve(10);//设置capacity的值为10  这时候size是0
    for (int i = 0; i <= 10; ++i) { //给vec6tian添加11个元素 则capacity翻倍20 size是11
         vec6.push_back(0);
    }
   
    cout << vec6.size() <<endl; //size 是具体有几个
    cout << vec6.capacity() << endl; //capacity 是容量
//string的特殊操做
    string str = "hello world!";
    str.insert(str.size(), 5, '2'); // 在str的最后一个字符后面添加5个2
    cout << str << endl;
    str.erase(str.size()-5,5); //从str的导数第五个开始删除5个字符
    cout << str << endl;
    string str1 = "012345678910";
    str.assign(str1,0,10); //把str1的从0位置开始的10个数字替换str原来的值
    cout << str << endl;
    const char *cp = "woaininiaiwome";
    str.insert(str.size(), cp+3); //在str的末尾 ，添加cp从第三个开始到最后结尾的字符
    cout << str <<endl;
    string s = "some string",s2 = " some other string";
//    s.insert(0, s2); 在s的0位置之前插入s2的拷贝
    s.insert(0,s2,0,s2.size()); // 在s的0位置之后添加 s2从0开始到s2.size()结尾的字符
    cout << s << endl;
    s2.append(" i'm looking for my conterpart"); //在字符串尾部添加  相当于s2.insert(s2.size(),"str")
    cout << s2 << endl;
    s2.replace(12, 6, "I 'm looking for my conterpart"); //从第12位开始的6个字母删除，替换成后面字符串的形式
    cout << s2 << endl;
    cout << "----------"<<endl;
    //搜索字符串
    /*s.find(args) 查找在s中args第一次出现的位置
     *s.rfind(args) 查找在s中args最后一次出现的位置
     *s.find_first_of(args) 在s中查找args中任何一个字符第一次出现的位置
     *s.find_last_of(args) 在s中查找args中任何一个字符最后一次出现的位置
     *s.find_first_not_of(args) 在s中查找第一个不在args中的字符
     *s.find_last_not_of(args) 在s中查找最后一个不在args中的字符
     */
     string name = "what's your name?";
     auto pos =  name.find("a",0);//2 //返回的是第一次出现的下标  0这个参数是可以省略的因为默认就是0
     cout << pos << endl;
     pos = name.rfind("a");//13
     cout << pos << endl;
     pos = name.find_first_of("aeiou");//2 在第二个位置出现了aeiou 里面的一个字符
     cout << pos << endl;
     pos = name.find_first_not_of("aeiou");//0 //在第一个字符出现了非aeiou的字符
     cout << pos << endl;
    cout << "---------"<< endl;
    //字符串的比较
    string name1 = "what's your name?";
    const char *name3 = "what's your name?";
    auto res = name.compare(name1);
    cout << res << endl; //0代表等于，大于是证书 小于负数
    res = name.compare(0,5,name1); //从name的第0位开始的5个字符 和name1比较
    cout << res << endl;
    res = name1.compare(0,5,name1,0,5); //从name的第0位开始的5个字符和name1从第0个开始的5个字符比较
    cout << res << endl;
    res = name1.compare(name3);
    cout << res << endl;
    cout << "-----------"<<endl;
    //字符串转数字和数字转字符串
    int i = 43;
    string num = to_string(i); //把数字转换成字符串
    string bstr = "3.14";
    double db = stod(bstr);
    string pi = "pi = 3.14";
    db = stod(pi.substr(pi.find_first_of("+-.1234567890"))); //substr(0,5) 表示从0位置开始截取5位
    cout << db << endl;
    return 0;
}
