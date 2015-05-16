//
//  common.cpp
//  学生事务管理
//
//  Created by 王翛然 on 15/5/14.
//  Copyright (c) 2015年 王翛然. All rights reserved.
//

#include "common.h"
#include <iostream>
#include <string.h>

//.查询课程具体信息 2.查询任课教师具体信息 3.查询课程历史纪录 如承担过该课的老师及用书

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

void BaseAction::output(const char *temp)
{
    mysql_query(&mysql, "set names utf8");
    mysql_query(&mysql, temp);
    MYSQL_RES *result = mysql_store_result(&mysql);
    unsigned int num_fields = mysql_num_fields(result);
    unsigned long row = mysql_num_rows(result);
    
    if(row == 0)
    {
        std::cout << "查询结果为空，请确认后重新输入.\n";
        return;
    }
    
    MYSQL_ROW raw;
    while((raw = mysql_fetch_row(result)))
    {
        for(size_t i = 0; i < num_fields; ++i)
            std::cout << raw[i] << " ";
    }
    
    mysql_free_result(result);
}


bool BaseAction::quit()
{
    std::cout << "返回上一层，请按'"
              << "Y'\n";
    
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
fuck1:
    std::cout << "请输入所需查询信息编号:\n"   <<
                 "1.查询课程具体信息\t\n"     <<
                 "2.查询任课教师具体信息\t\n"  <<
                 "3.查询课程历史纪录及详细信息\t\n" <<
                 "4.";
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
            case 3:
                lookupHistory();
                break;
            default:
                std::cout << "please input right" <<
                             "fucking number.\n";
                break;
        }
        goto fuck1;
    }
    mysql_close(&mysql);
}

void BaseAction::lookupCourse()
{
fuck2:
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
                std::cout << "please input right " <<
                             "fucking number.\n";
                break;
        }
        goto fuck2;
    }
}

void BaseAction::CourseBrief()
{
    char ID[255];
    char temp[255];
    
    std::cout << "please input the subject ID :";
    std::cin >> ID;
    
    strcat(temp, "select * from subjects where subID = ");
    strcat(temp, ID);
    output(temp);
}

void BaseAction::lookupTeacher()
{
    char ID[255];
    char temp[255];
    std::cout << "please input the teachers ID :";
    std::cin >> ID;
    
    strcat(temp, "select brief from teachers where tecID = ");
    strcat(temp, ID);
    output(temp);
}

void BaseAction::lookupHistory()
{
fuck3:
    std::cout << "请输入所需查询课程具体信息序号:\n" <<
                 "1.某课程历史纪录\n"               <<
                 "2.某课老师历史纪录\n"
                 "3.";
    bool q = quit();
    int num = 0;
    
    while(q)
    {
        char ID[255];
        char temp[255];
        std::cin >> num;
        switch (num)
        {
            case 1:
                strcat(temp, "select subject, book, brief,firstTime     from history, subjects, tecSub where history.tecID = tecSub.tecID and history.subID =  ");
                break;
            case 2:
                strcat(temp, "select name from teachers, history where history.tecID = teachers.tecID and history.subID = ");
                break;
            default :
                std::cout << "please input the fucking right number!!!";
                continue;
        }

        std::cout << "please input the subject ID :";
        std::cin >> ID;
        strcat(temp, ID);
    
        output(temp);
        std::cout << std::endl;
        goto fuck3;
    }
}