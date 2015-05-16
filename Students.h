//
//  Student.h
//  C++ test
//
//  Created by 王翛然 on 15/5/13.
//  Copyright (c) 2015年 王翛然. All rights reserved.
//

#ifndef __C___test__Student__
#define __C___test__Student__

#include <string>
#include <string.h>
#include "common.h"

class STUDENTS : public BaseAction
{
public:
    STUDENTS();
    STUDENTS(char *ID, const std::string &password) : BaseAction(),
        _stuID(ID) { strcpy(_Password, password.data()); }
    bool check(char *account, char *password);
private:
    char *_stuID;
    char _Password[255];
};

#endif /* defined(__C___test__Student__) */
