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
        goto label;
    }
}

void TEACHERS::update()
{
    bool q = true;
    int num = 0;
label:
    std::cout << "1.更新用书\n"    <<
                 "2.更新课程大纲\n" <<
                 "3."             ;
    q = quit();
    if (q)
    {
        std::cin >> num;
        switch (num)
        {
            case 1:
                updateBook();
                break;
            case 2:
                updateContent();
                break;
            default:
                std::cout << "请输入正确的数字\n";
                break;
        }
        goto label;
    }
}

std::pair<std::string, std::string> TEACHERS::getInfo(int num)
{
    std::string subID;
    std::cout << "请输入所需修改科目编号: ";
    std::cin >> subID;
    
    std::string temp {"select * from tecSub where tecID = "};
    temp += _tecID + " and subID = " + subID;
    
    if (!checkSub(temp))
    {
        std::cout << "您没有此课程，请查证后重试!!!\n";
        return std::make_pair("", "");
    }
    if(num == 1)
        std::cout << "请输入教材名称: ";
    else
        std::cout << "请输入课程大纲: ";
    std::string info;
    std::cin >> info;
    
    return std::make_pair(subID, info);
}

bool TEACHERS::checkSub(const std::string& temp)
{
    if (item(temp) == 0)
        return false;
    return true;
}

void TEACHERS::updateBook()
{
    auto a = getInfo(1);
    if(a.first != "" && a.second != "")
    {
        std::string temp {"update tecSub set Book = '"};
        temp += a.second + "'where tecID = " + _tecID + " and subID = " + a.first;
        add(temp);
        std::cout << "更新成功!!!\n";
    }
}

void TEACHERS::updateContent()
{
    auto a = getInfo(2);
    
    if(a.first != "" && a.second != "")
    {
        std::string temp {"update tecSub set contents = '"};
        temp += a.second + "'where tecID = " + _tecID + " and subID = " + a.first;
        
        add(temp);
        std::cout << "更新成功!!!\n";
    }
}