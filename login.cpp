//
//  login.cpp
//  学生事务管理
//
//  Created by 王翛然 on 15/5/15.
//  Copyright (c) 2015年 王翛然. All rights reserved.
//

#include "login.h"
#include "Teachers.h"
#include "Managers.h"
#include "Students.h"
#include <iostream>

bool Login::quit()
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

void Login::show()
{
    bool q;
    int num = 0;
fuck:
    std::cout << "please choose you character:\n" <<
                 "1.Administrator.\n"            <<
                 "2.Teachers.\n"                 <<
                 "3.Students.\n"                 <<
                 "4."                            <<
                 "如无账号请注册: "                ;
    
    q = quit();
    if(q)
    {
        std::cin >> num;
        switch (num)
        {
            case 1:
                admin();
                break;
            case 2:
                teach();
                break;
            case 3:
                stu();
                break;
            default:
                break;
        }
        goto fuck;
    }
}

void Login::admin()
{
    std::cout << "please input your account: ";
    char Admin[12];
    std::cin >> Admin;
    
    std::cout << "please input your password: ";
    char password[19];
    std::cin >> password;
    
    MANAGERS a(Admin, password);
    if(!a.check(Admin, password))
    {
        std::cout << "账号或密码错误，请查认后输入！！！\n";
        return;
    }
    else
    {
        a.show();
    }
}

void Login::teach()
{
    std::cout << "please input your account: ";
    char Admin[12];
    std::cin >> Admin;
    
    std::cout << "please input your password: ";
    char password[19];
    std::cin >> password;
    
    TEACHERS a(Admin, password);
    if(!a.check(Admin, password))
    {
        std::cout << "账号或密码错误，请查认后输入！！！";
        return;
    }
    else
    {
        a.show();
    }
}

void Login::stu()
{
    std::cout << "please input your account: ";
    char student[12];
    std::cin >> student;
    
    std::cout << "please input your password: ";
    char password[19];
    std::cin >> password;
    
    STUDENTS a(student, password);
    if(!a.check(student, password))
    {
        std::cout << "账号或密码错误，请查认后输入！！！";
        return;
    }
    else
    {
        a.show();
    }
}