#pragma once

#include <iostream>
#include <map>

#include "DBConnection.h"
#include <cppconn/resultset.h> //這是 C++ Connector 用來處理 SQL 查詢結果的標頭文件。
#include <cppconn/statement.h> // Statement 是用來執行 SQL 查詢和更新
#include "User.h"
#include "UserCommand.h"
#include "UserFactory.h"
#include "UserCommandFactory.h"

class System
{
private:
    static System* sys;
    DBConnection* dbconnection;
    Connection* conn;

    System();
    System(const System &) = delete;
    System& operator=(const System &) = delete;


public:
    UserFactory* userfactory;
    ResultSet* res;
    map<int,UserCommandFactory*> UserCommandFactory;
    static System* getInstance(); //getInstance() 必須是靜態的，這樣才能通過類名直接訪問，從而創建或返回唯一的靜態物件。
    void showMenu(); //啟動系統
    void logIn(); //用戶登入
    void signUp(); //用戶註冊
    void userMainFunction(); //用戶主要功能
    ~System(); //清理資源
};