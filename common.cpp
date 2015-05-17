//
//  common.cpp
//  学生事务管理
//
//  Created by 王翛然 on 15/5/14.
//  Copyright (c) 2015年 王翛然. All rights reserved.
//

#include "common.h"
#include <iostream>

bool BaseAction::connect(const char *host, const char *user,
                         const char *password, const char *db,
                         unsigned int port,
                         const char *unix_socket,
                         unsigned long flag)
{
    if(mysql_real_connect(&mysql, host, user,
                           password, db, port,
                           unix_socket, flag) != nullptr)
        return true;
    return false;
}

bool BaseAction::check(const std::string &temp)
{
    connect("localhost", "root", "wjwjksning1995..",
            "stuInfoManagement", 3306, nullptr, 0);
    mysql_query(&mysql, "set names utf8");
    mysql_query(&mysql, temp.data());
    MYSQL_RES *result = mysql_store_result(&mysql);
    
    unsigned long row = mysql_num_rows(result);
    mysql_close(&mysql);
    mysql_free_result(result);
    
    if(row == 0)
        return false;
    return true;
}

void BaseAction::output(const std::string &temp)
{
    mysql_query(&mysql, "set names utf8");
    mysql_query(&mysql, temp.data());
    MYSQL_RES *result = mysql_store_result(&mysql);
    unsigned long row = mysql_num_rows(result);
    
    if(row == 0)
    {
        std::cout << "查询结果为空，请确认后重新输入.\n";
        return;
    }
    
    MYSQL_ROW raw;
    unsigned int num_fields = mysql_num_fields(result);
    while((raw = mysql_fetch_row(result)))
    {
        for(size_t i = 0; i < num_fields; ++i)
            std::cout << raw[i] << " ";
        std::cout << "\n";
    }
    
    mysql_free_result(result);
}


bool BaseAction::quit()
{
    std::cout << "返回上一层，请按Y\n";
    
    char q;
    std::cin >> q;
    if(q == 'y' || q == 'Y')
        return false;
    std::cin.putback(q);
    return true;
}

void BaseAction::show()
{
    connect("localhost", "root", "wjwjksning1995..",
            "stuInfoManagement", 3306, nullptr, 0);
    int num = 0;
    bool q = true;
Label1:
    std::cout << "请输入所需查询信息编号:\n"   <<
                 "1.查询课程具体信息\n"     <<
                 "2.查询任课教师具体信息\n"  <<
                 "3.";
    q = quit();
    
    if (q)
    {
        std::cin >> num;
        switch (num)
        {
            case 1:
                lookupCourse();
                break;
            case 2:
                lookupTeacher();
                break;
            default:
                std::cout << "请输入正确的编号\n";
                break;
        }
        goto Label1;
    }
    mysql_close(&mysql);
}

void BaseAction::lookupCourse()
{
Label2:
    std::cout << "请输入所需查询课程具体信息序号:\n" <<
                 "1.课程简介\n"                  <<
                 "2.课程历史纪录\n"               <<
                 "3.";
    bool q = true;
    q = quit();
    int num = 0;
    while (q)
    {
        std::cin >> num;
        
        switch (num)
        {
            case 1:
                CourseBrief();
                break;
            case 2:
                lookupHistory();
                break;
            default:
                std::cout << "请输入正确的编号.\n";
                break;
        }
        goto Label2;
    }
}

void BaseAction::CourseBrief()
{
    std::cout << "请输入课程编号 :";
    std::string ID;
    std::cin >> ID;
    
    std::string temp {"select subject, name, subjects.brief from subjects, tecSub, teachers where subjects.subID = tecSub.subID and tecSub.tecID = teachers.tecID and subjects.subID = "};
    temp += ID;
    output(temp);
}

void BaseAction::lookupTeacher()
{
    bool q = true;
    int num = 0;
Label:
    std::cout << "1.老师个人简介\n" <<
                 "2.老师评价\n" <<
                 "3.";
    q = quit();

    if (q)
    {
        std::string temp;
        std::cin >> num;
        
        std::cout << "请输入老师编号: ";
        std::string ID;
        std::cin >> ID;
        switch (num)
        {
            case 1:
                temp={"select brief from teachers where tecID = "};
                break;
            case 2:
                temp={"select comment from evaluation where tecID = "};
                break;
            default:
                break;
        }
        temp += ID;
        output(temp);
        goto Label;
    }
}

void BaseAction::lookupHistory()
{
    bool q = true;
    int num = 0;
Label3:
    std::cout << "请输入所需查询课程具体信息序号:\n" <<
                 "1.某课程历史纪录\n"               <<
                 "2.某课老师历史纪录\n"
                 "3.";
    q = quit();
    if (q)
    {
        std::cin >> num;
        std::string ID;
        std::string temp;
        switch (num)
        {
            case 1:
                temp = "select subject, brief,firstTime     from history, subjects, tecSub where history.subID = subjects.subID and history.subID = ";
                break;
            case 2:
                temp = "select name from teachers, history where history.tecID = teachers.tecID and history.subID = ";
                break;
            default :
                std::cout << "请输入正确的编号!!!\n";
                goto Label3;
                break;
        }
        std::cout << "请输入课程编号: ";
        std::cin >> ID;
        temp += ID;
    
        output(temp);
        goto Label3;
    }
}