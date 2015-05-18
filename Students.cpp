//
//  Student.cpp
//  C++ test
//
//  Created by 王翛然 on 15/5/13.
//  Copyright (c) 2015年 王翛然. All rights reserved.
//

#include "Students.h"
#include <iostream>

bool STUDENTS::check()
{
    std::string temp = {"select* from students where stuID = "};
    temp += _stuID + " and password = '" + _Password + "'";
    return BaseAction::check(temp);
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

void STUDENTS::evaluate()
{
    std::string temp = {"select evaluateID from evaluation"};
    unsigned long evaID = 0;
    evaID = item(temp) + 1;
    
    std::cout << "请输入想评价老师的ID:";
    std::string tecID;
    std::cin >> tecID;
    
    std::cout << "请输入评价内容:";
    std::string comments;
    std::cin >> comments;
    
    temp = {"insert into evaluation value("};
    temp += std::to_string(evaID) + ", '" + tecID + "', '" +comments + "')";
    add(temp);
    
    std::cout << "评价成功\n";
}

