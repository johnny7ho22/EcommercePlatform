#include "User.h"
#include "DBConnection.h"
#include <cppconn/resultset.h> //這是 C++ Connector 用來處理 SQL 查詢結果的標頭文件。
#include <cppconn/statement.h> // Statement 是用來執行 SQL 查詢和更新

class Command 
{
public:
    DBConnection* dbconnection;
    Connection* conn;
    Command();
    virtual void execute() = 0;
    virtual ~Command() = default;
};

//顯示菜單
class ShowMenuCommand : public Command 
{
private:
    User* user;

public:
    ShowMenuCommand(User* user);
    void execute();
};

//顯示商品
class ShowProductCommand : public Command
{
private:
    User* user;

public:
    ShowProductCommand(User* user);
    void execute();

};

//顯示訂單
class ShowOrderCommand : public Command
{
private:
    User* user;
public:
    ShowOrderCommand(User* user);
    void execute();
};

//刪除訂單
class DeleteOrderCommand : public Command
{
private:
    User* user;
public:
    DeleteOrderCommand(User* user);
    void execute();
};

//確認訂單
class ConfirmOrderCommand : public Command
{
private:
    User* user;
public:
    ConfirmOrderCommand(User* user);
    void execute();
};

//修改個人資訊
class EditUserInfo : public Command
{
private:
    User* user;
public:
    EditUserInfo(User* user);
    void execute();
};

// 購買商品
class BuyProductCommand : public Command
{
private:
    Command* command;
    int id;

public:
    BuyProductCommand(Command* command, int id);
    void execute();
};

//上架商品
class SellProductCommand : public Command
{
private:
    Command* command;
    int id;

public:
    SellProductCommand(Command* command, int id);
    void execute();
};

//刪除商品
class DeleteProductCommand : public Command
{
private:
    Command* command;
    int id;

public:
    DeleteProductCommand(Command* command);
    void execute();
};

//查看用戶
class ShowUserCommand : public Command
{
public:
    ShowUserCommand();
    void execute();
};

//刪除用戶
class DeleteUserCommand : public Command
{
private:
    Command* command;
public:
    DeleteUserCommand(Command* command);
    void execute();
};





