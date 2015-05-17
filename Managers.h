//
//  Administrator.h
//  C++ test
//
//  Created by 王翛然 on 15/5/13.
//  Copyright (c) 2015年 王翛然. All rights reserved.
//

#ifndef __C___test__Administrator__
#define __C___test__Administrator__

#include "common.h"

class MANAGERS : public BaseAction
{
public:
    MANAGERS();
    MANAGERS(const std::string &manID, const std::string &password)
            : BaseAction(), _manID(manID), _Password(password) { }
    bool check();
    void show();
    void update();
private:
    std::string _manID;
    std::string _Password;
    unsigned long item(const std::string &temp);
};

#endif