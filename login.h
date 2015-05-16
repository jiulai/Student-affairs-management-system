//
//  login.h
//  学生事务管理
//
//  Created by 王翛然 on 15/5/15.
//  Copyright (c) 2015年 王翛然. All rights reserved.
//

#ifndef __________login__
#define __________login__

#include <mysql.h>
#include "Managers.h"
#include "Teachers.h"
#include "Students.h"

class Login
{
public:
    void show();
private:
    void admin();
    void teach();
    void stu();
    bool quit();
};
#endif /* defined(__________login__) */
