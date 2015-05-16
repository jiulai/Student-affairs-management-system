//
//  Teachers.h
//  学生事务管理
//
//  Created by 王翛然 on 15/5/14.
//  Copyright (c) 2015年 王翛然. All rights reserved.
//

#ifndef __________Teachers__
#define __________Teachers__

#include <string>
#include "common.h"
#include <string.h>
class TEACHERS : public BaseAction
{
public:
    TEACHERS();
    TEACHERS(char *ID, const std::string &password) : BaseAction()
        { strcat(_tecID, ID); _Password = password; }
    bool check(char *account, char *password);
private:
    char _tecID[19];
    std::string _Password;
};


#endif /* defined(__________Teachers__) */
