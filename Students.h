//
//  Student.h
//  C++ test
//
//  Created by 王翛然 on 15/5/13.
//  Copyright (c) 2015年 王翛然. All rights reserved.
//

#ifndef __C___test__Student__
#define __C___test__Student__

#include "common.h"

class STUDENTS : public BaseAction
{
public:
    STUDENTS();
    STUDENTS(const std::string &ID, const std::string &password) :
                BaseAction(), _stuID(ID), _Password(password) { }
    bool check();
    void evaluate();
    void show();
private:
    std::string _stuID;
    std::string _Password;
};

#endif /* defined(__C___test__Student__) */
