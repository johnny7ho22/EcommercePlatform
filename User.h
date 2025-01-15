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
    
    virtual void showMenu() = 0; //顯示菜單
    virtual void showProduct() = 0; //顯示商品
    virtual void showOrder() = 0; //查看訂單
    virtual void deleteOrder() = 0; //刪除訂單
    virtual void confirmOrder() = 0; //確認訂單
        
    ~User();
};