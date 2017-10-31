//
//  genericMethod.cpp
//  studyCPP
//
//  Created by slimdy on 2017/10/30.
//  Copyright © 2017年 slimdy. All rights reserved.
//

#include "genericMethod.hpp"
#include <numeric>

bool isShorter(const string &s1,const string &s2){
    return s1.size() <s2.size();
}


//泛型算法 即代表 并不是在某一类数据类型上进行操作，而是在所有的容器类型都能操作，它操作的是迭代器(指针),而不是具体某个值
int studyGenericMethod(){
//只读算法
    vector<int> vec1 = {1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8};
    //find
    auto res = find(vec1.begin(), vec1.end(), 11); //返回的是找到该元素的迭代器，如果找不到就会返回第二个参数，也就是范围内最小的
    cout << *res << endl;
    //count
    auto i = count(vec1.begin(), vec1.end(), 9); //9在vec中出现的次数
    cout << i << endl;
    //accumulate
    int sum = accumulate(vec1.begin(), vec1.end(), 0); //初始值 是0 也就是从vec1的开始到结束 相加
    cout << sum << endl;
    vector<string> vec2 = {"a","e","i","o","u"};
    string empty = "";
    string str =accumulate(vec2.cbegin(), vec2.cend(),empty); //这里不能直接把空字符串丢过来，因为他是常量 造成无法计算
    cout << str << endl;
    //equal
    vector<int> vec3 = {1,2,3,4,5,6,7,8,9};
    bool r = equal(vec3.cbegin(), vec3.cend(), vec1.cbegin()); //比较是否相同，可以使不同数据类型，甚至是元素类型,它假设第二个序列比第一个序列长，或者起码等于
    cout << r << endl;
//写算法
    fill(vec3.begin(), vec3.end(), 0); //从 begin 到 end 填充0
//    for (auto i : vec3)
//        cout << i << endl; //全部替换成了0
    vector<int> vec4;
    //fill_n 从begin开始多少个元素 全部初始化为11
    fill_n(vec4.begin(), vec4.size(), 11); //对于没有定义的那容器，无法得知其容量大小，用这个方法无效。知道大小后，这个方法就有效了
    for (auto i : vec4)
        cout << i << endl;
    //back _ inserter
    auto it = back_inserter(vec4); //这个的含义是 创建一个末尾的迭代器，如果修改这个迭代器的值就相当于push。back一个元素进入这个迭代器关联的容器
    *it = 42;
    for (auto i : vec4)
        cout << i << endl;
    //copy replace
    vector<int> vec5(17);
    copy(vec1.begin(), vec1.end(), vec5.begin());
    // replace(vec1.begin(), vec1.end(), 1, 42); //把vec1中的1 替换成42
    
//排序
    vector<string> vec6 = {"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
    sort(vec6.begin(), vec6.end());
    auto end_unique = unique(vec6.begin(), vec6.end()); //他会把所有元素里的重复项全部放在最后，并返回一个迭代器指向最后一个不重复项
    vec6.erase(end_unique,vec6.end()); //输出重复项
    for (auto i : vec6) {
        cout << i << endl;
    }
    //自定义排序
    cout << "-----------------" << endl;
//    sort(vec6.begin(), vec6.end(), isShorter);
//    for (auto i : vec6) {
//        cout << i << endl;
//    }
    stable_sort(vec6.begin(), vec6.end(), isShorter); //当他们排序完后，字母个数相等的按照之前排序，而如果不用statble，就有可能打乱
    for (auto i : vec6) {
        cout << i << endl;
    }
    
    
//简单的lambda
    int v1 = 42;
    auto f = [v1](int v2){return v1+v2;}; //捕捉的v1在第一的时候就已将完成了 也就是说f在生成的时候就已经v1是42了。后面再怎么改变都不影响f的调用，换成引用就可以让他随着v1的改变而改变了
    cout <<f(10) << endl;
    v1 = 0;
    cout <<f(10) << endl;
    return 0;
}
