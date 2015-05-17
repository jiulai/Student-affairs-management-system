//
//  login.cpp
//  学生事务管理
//
//  Created by 王翛然 on 15/5/15.
//  Copyright (c) 2015年 王翛然. All rights reserved.
//

#include <iostream>
#include "login.h"
#include "Teachers.h"
#include "Managers.h"
#include "Students.h"

bool Login::quit()
{
    std::cout << "返回上一层,请按Y\n";
    
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
    std::cout << "选择你的身份 \n"     <<
                 "1.管理员\n"         <<
                 "2.教师\n"           <<
                 "3.学生\n"           <<
                 "4.注册\n"           <<
                 "5."                ;
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
            case 4:
                signIn();
                break;
            default:
                std::cout << "请输入正确的数字\n";
                break;
        }
        goto fuck;
    }
}

void Login::admin()
{
    std::cout << "账号: ";
    char user[12];
    std::cin >> user;
    
    std::cout << "密码: ";
    char password[19];
    std::cin >> password;
    
    MANAGERS a(user, password);
    if(!a.check())
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
    std::cout << "账号: ";
    char user[12];
    std::cin >> user;
    
    std::cout << "密码: ";
    char password[19];
    std::cin >> password;
    
    TEACHERS a(user, password);
    if(!a.check())
    {
        std::cout << "账号或密码错误，请查认后输入！！！\n";
        return;
    }
    else
    {
        a.show();
    }
}

void Login::stu()
{
    std::cout << "账号: ";
    char user[12];
    std::cin >> user;
    
    std::cout << "密码: ";
    char password[19];
    std::cin >> password;
    
    STUDENTS a(user, password);
    if(!a.check())
    {
        std::cout << "账号或密码错误，请查认后输入！！！\n";
        return;
    }
    else
    {
        a.show();
    }
}

void Login::signIn()
{
    bool q = true;
    int num = 0;
label:
    std::cout << "1.注册老师账号请按1\n" <<
                 "2.注册学生账号请按2\n" <<
                 "3."   ;
    q = quit();
    
    if (q)
    {
        std::cin >> num;
        switch (num)
        {
            case 1:
                signTec();
                break;
            case 2:
                signStu();
                break;
            default:
                std::cout << "请输入正确的数字!!!\n";
                break;
        }
        goto label;
    }
}

void Login::signTec()
{
    std::cout << "账号: ";
    std::string tecID;
    std::cin >> tecID;
    
    std::cout << "密码: ";
    std::string password;
    std::cin >> password;
    
    TEACHERS a(tecID, password);
    if (!a.check())
    {
        std::string s, s1;
        
        std::cout << "姓名: ";
        std::cin >> s1;
        (s += "'") += s1 + "'";
        
        std::cout << "性别: ";
        std::cin >> s1;
        (s += ",'") += s1 + "',";
        
        std::cout << "个人简介(不超过255个字): ";
        getline(std::cin, s1);
        (s += "'") += s1 + "')";
        
        std::string temp = {"insert into teachers value( "};
        temp += tecID + ", '" + password + "', " + s.data();
        
        if (addUser(temp))
            std::cout << "注册成功，请登陆.\n";
        else
            std::cout << "注册失败(未知原因)，请重新注册.\n";
    }
    else
    {
        std::cout << "已存在账号，请重新注册.\n";
    }
}

void Login::signStu()
{
    std::cout << "账号: ";
    std::string stuID;
    std::cin >> stuID;
    
    std::cout << "密码: ";
    std::string password;
    std::cin >> password;
    
    STUDENTS a(stuID, password);
    if (!a.check())
    {
        std::string s, s2;
        
        std::cout << "姓名: ";
        std::cin >> s2;
        (s += "'") += s2 + "'";
        
        std::cout << "性别: ";
        std::cin >> s2;
        (s += ",'") += s2 + "')";
        
        std::string temp {"insert into students value("};
        temp += stuID + ", '" + password + "', " + s.data();
        
        if(addUser(temp))
            std::cout << "注册成功，请登陆.\n";
        else
            std::cout << "注册失败(未知原因)，请重新注册.\n";
    }
    else
    {
        std::cout << "已存在账号，请重新注册.\n";
    }
}

bool Login::addUser(const std::string &temp)
{
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_real_connect(&mysql, "localhost", "root",
                       "wjwjksning1995..", "stuInfoManagement",
                       3306, nullptr, 0);
    
    mysql_query(&mysql, "set names utf8");
    mysql_query(&mysql, temp.data());
    mysql_close(&mysql);
    return true;
}