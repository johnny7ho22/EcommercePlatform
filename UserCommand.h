#pragma once
#include "User.h"
#include "DBConnection.h"
#include <cppconn/resultset.h> //這是 C++ Connector 用來處理 SQL 查詢結果的標頭文件。
#include <cppconn/statement.h> // Statement 是用來執行 SQL 查詢和更新

class UserCommand 
{
public:
    DBConnection* dbconnection;
    Connection* conn;
    UserCommand();
    virtual void execute() = 0;
    virtual ~UserCommand() = default;
};







