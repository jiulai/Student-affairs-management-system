//
//  Teachers.cpp
//  学生事务管理
//
//  Created by 王翛然 on 15/5/14.
//  Copyright (c) 2015年 王翛然. All rights reserved.
//

#include "Teachers.h"
#include <iostream>

bool TEACHERS::check()
{
    std::string temp {"select* from teachers where tecID = "};
    temp += _tecID + " and password = '" + _Password + "'";
    return BaseAction::check(temp);
}

void TEACHERS::show()
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
    }
    goto label;
}

void TEACHERS::update()
{
    std::string subID;
    std::cout << "请输入所需修改科目编号: ";
    std::cin >> subID;
    
    std::cout << "请输入修改内容: ";
    std::string contents;
    getline(std::cin, contents);
    
    mysql_init(&mysql);
    connect("localhost", "root", "wjwjksning1995..",
            "stuInfoManagement", 3306, nullptr, 0);
    
    std::string temp {"update tecSub set contents = "};
    temp += contents + "where tecID = " + _tecID + " and subID = " + subID;
    mysql_query(&mysql, "set names utf8");
    mysql_query(&mysql, temp.data());
    std::cout << "更新成功!!!\n";
}
