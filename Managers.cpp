//
//  Administrator.cpp
//  C++ test
//
//  Created by 王翛然 on 15/5/13.
//  Copyright (c) 2015年 王翛然. All rights reserved.
//

#include "Managers.h"
#include <iostream>

bool MANAGERS::check()
{
    std::string temp = {"select * from Mangers where manID = "};
    temp += _manID + " and password = '" + _Password + "'";
    return BaseAction::check(temp);
}

void MANAGERS::show()
{
    
    bool q = true;
    int num = 0;
label:
    std::cout << "1.查询\n" <<
                 "2.更新\n" <<
                 "3.";
    q = quit();
    if (q)
    {
        std::cin >> num;
        switch (num)
        {
            case 1:
                BaseAction::show();
                break;
            case 2:
                update();
                break;
            default:
                std::cout << "请输入正确的数字\n";
                break;
        }
        goto label;
    }
}

unsigned long MANAGERS::item(const std::string &temp)
{
    MYSQL my;
    mysql_init(&my);
    if(mysql_real_connect(&my, "localhost", "root",
                          "wjwjksning1995..",
                          "stuInfoManagement", 3306, nullptr, 0))
    {
        mysql_query(&my, "set names utf8");
        mysql_query(&my, temp.data());
        MYSQL_RES *result = mysql_store_result(&my);
        unsigned long row = mysql_num_rows(result);
        mysql_free_result(result);
        mysql_close(&my);
        return row;
    }
    return -1;
}

void MANAGERS::update()
{
    std::cout << "请输入需要安排课程的老师的编号: ";
    std::string tecID;
    std::cin >> tecID;
    
    std::cout << "请输入需要课程的的编号: ";
    std::string subID;
    std::cin >> subID;
    
    std::string temp = "select * from tecSub where tecID = " + tecID + " and subID = " + subID;
    auto row = item(temp);

    if (row == 0)
    {
        temp = "insert into tecSub value(" ;
        temp += tecID + "," + subID + ", 'NULL', 'NULL')";
        item(temp);
    }
    temp = "select * from tecSub where tecID = " + tecID + " and subID = " + subID;
    if (item(temp))
        std::cout << "更新成功!!\n";
}