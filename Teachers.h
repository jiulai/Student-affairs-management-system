//
//  Teachers.h
//  学生事务管理
//
//  Created by 王翛然 on 15/5/14.
//  Copyright (c) 2015年 王翛然. All rights reserved.
//

#ifndef __________Teachers__
#define __________Teachers__

#include "common.h"
#include <utility>

class TEACHERS : public BaseAction
{
public:
    TEACHERS();
    TEACHERS(const std::string &ID, const std::string &password) :
                BaseAction(), _tecID(ID), _Password(password) { }
    bool check();
    void show();
private:
    std::string _tecID;
    std::string _Password;
    void update();
    void updateBook();
    void updateContent();
    bool checkSub(const std::string&);
    std::pair<std::string, std::string> getInfo(int num);
};


#endif /* defined(__________Teachers__) */
