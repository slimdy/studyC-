//
//  studyIO.hpp
//  studyCPP
//
//  Created by slimdy on 2017/10/24.
//  Copyright © 2017年 slimdy. All rights reserved.
//

#ifndef studyIO_hpp
#define studyIO_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
int studyIO();
struct PersonInfo{
    string name;
    vector<string> phones;
};
#endif /* studyIO_hpp */
