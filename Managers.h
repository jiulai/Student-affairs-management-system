//
//  Administrator.h
//  C++ test
//
//  Created by 王翛然 on 15/5/13.
//  Copyright (c) 2015年 王翛然. All rights reserved.
//

#ifndef __C___test__Administrator__
#define __C___test__Administrator__

#include <string>
#include <string.h>
#include "common.h"

class MANAGERS : public BaseAction
{
public:
    MANAGERS();
    MANAGERS(char *manID, const std::string &password) :
                            BaseAction(), _manID(manID)
                            { strcpy(_Password, password.data()); }
    bool check(char *account, char *password);
private:
    char *_manID;
    char _Password[19];
};

#endif /* defined(__C___test__Administrator__) */
