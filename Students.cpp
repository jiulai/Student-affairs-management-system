//
//  Student.cpp
//  C++ test
//
//  Created by 王翛然 on 15/5/13.
//  Copyright (c) 2015年 王翛然. All rights reserved.
//

#include "Students.h"
#include <iostream>

int STUDENTS::evaID = 1;

bool STUDENTS::check()
{
    std::string temp = {"select* from students where stuID = "};
    temp += _stuID + " and password = '" + _Password + "'";
    return BaseAction::check(temp);
}

void STUDENTS::evaluate()
{
    std::cout << "请输入想评价老师的ID:";
    std::string tecID;
    std::cin >> tecID;
    
    std::cout << "请输入评价内容:";
    std::string comments;
    getline(std::cin, comments);
    
    std::string temp {"insert into evaluation value("};
    temp += std::to_string(evaID++) + ", '" + tecID + "', '" +
                                                comments + "')";
    
    mysql_init(&mysql);
    connect("localhost", "root", "wjwjksning1995..",
            "stuInfoManagement", 3306, nullptr, 0);
    mysql_query(&mysql, "set names utf8");
    
    mysql_query(&mysql, temp.data());
    mysql_close(&mysql);
}

void STUDENTS::show()
{
    bool q = true;
    int num = 0;
label:
    std::cout << "1.查询\n" <<
                 "2.评价\n" <<
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
                evaluate();
                break;
            default:
                std::cout << "请输入正确的数字!!!\n";
                break;
        }
        goto label;
    }
}