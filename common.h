//
//  common.h
//  学生事务管理
//
//  Created by 王翛然 on 15/5/14.
//  Copyright (c) 2015年 王翛然. All rights reserved.
//

#ifndef __________common__
#define __________common__

#include <string>
#include <mysql.h>

class BaseAction
{
public:
    BaseAction() { mysql_init(&mysql); }
    virtual void show();
protected:
    MYSQL mysql;
    virtual bool connect(const char *host, const char *user,
                         const char *password, const char *db,
                         unsigned int port,
                         const char *unix_socket,
                         unsigned long flag);
    virtual bool check(const std::string &temp);
    virtual bool quit();
private:
    virtual void lookupHistory();
    virtual void lookupCourse();
    virtual void lookupTeacher();
    virtual void CourseBrief();
    virtual void output(const std::string&);
};

#endif /* defined(__________common__) */
