//
//  Student.cpp
//  C++ test
//
//  Created by 王翛然 on 15/5/13.
//  Copyright (c) 2015年 王翛然. All rights reserved.
//

#include "Students.h"

bool STUDENTS::check(char *account, char *password)
{
    char temp[255] = {"select* from students where stuID = "};
    
    strcat(temp, account);
    strcat(temp, " and password = '");
    strcat(temp, password);
    strcat(temp, "'");
    
    connect("localhost", "root", "wjwjksning1995..",
            "stuInfoManagement", 3306, nullptr, 0);
    
    mysql_query(&mysql, "set names utf8");
    mysql_query(&mysql, temp);
    MYSQL_RES *result = mysql_store_result(&mysql);
    
    unsigned long row = mysql_num_rows(result);
    mysql_close(&mysql);
    mysql_free_result(result);
    if(row == 0)
        return false;
    return true;
}