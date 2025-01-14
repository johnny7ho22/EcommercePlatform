#pragma once

#include "DBConnection.h"
#include <cppconn/resultset.h> //這是 C++ Connector 用來處理 SQL 查詢結果的標頭文件。
#include <cppconn/statement.h> // Statement 是用來執行 SQL 查詢和更新


#include <string>  // 引入 string 類別
#include <iostream>


class User
{
public:
    int id;
    string name;
    int age;
    int role;
    string password;

    DBConnection* dbconnection;
    Connection* conn;

    User();
    virtual void userMainFunction() = 0; //用戶功能
    void editUserInfo(User* user); //修改個人資訊
    ~User();
};