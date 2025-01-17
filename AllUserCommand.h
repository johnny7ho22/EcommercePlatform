#pragma once
#include "UserCommand.h"

//顯示菜單
class ShowMenuCommand : public UserCommand 
{
private:
    User* user;
    UserCommand* usercommand;

public:
    ShowMenuCommand(User* user, UserCommand* usercommand);
    void execute();
};

//顯示商品
class ShowProductCommand : public UserCommand
{
private:
    User* user;
    UserCommand* usercommand;

public:
    ShowProductCommand(User* user, UserCommand* usercommand);
    void execute();

};

//顯示訂單
class ShowOrderCommand : public UserCommand
{
private:
    User* user;
    UserCommand* usercommand;
public:
    ShowOrderCommand(User* user, UserCommand* usercommand);
    void execute();
};

//刪除訂單
class DeleteOrderCommand : public UserCommand
{
private:
    User* user;
    UserCommand* usercommand;
public:
    DeleteOrderCommand(User* user, UserCommand* usercommand);
    void execute();
};

//確認訂單
class ConfirmOrderCommand : public UserCommand
{
private:
    User* user;
    UserCommand* usercommand;

public:
    ConfirmOrderCommand(User* user, UserCommand* usercommand);
    void execute();
};

//修改個人資訊
class EditUserInfoCommand : public UserCommand
{
private:
    User* user;
    UserCommand* usercommand;

public:
    EditUserInfoCommand(User* user, UserCommand* usercommand);
    void execute();
};

// 購買商品
class BuyProductCommand : public UserCommand
{
private:
    User* user;
    UserCommand* usercommand;

public:
    BuyProductCommand(User* user, UserCommand* usercommand);
    void execute();
};

//上架商品
class SellProductCommand : public UserCommand
{
private:
    User* user;
    UserCommand* usercommand;

public:
    SellProductCommand(User* user, UserCommand* usercommand);
    void execute();
};

//刪除商品
class DeleteProductCommand : public UserCommand
{
private:
    User* user;
    UserCommand* usercommand;

public:
    DeleteProductCommand(User* user, UserCommand* usercommand);
    void execute();
};

//查看用戶
class ShowUserCommand : public UserCommand
{
private:
    User* user;
    UserCommand* usercommand;
public:
    ShowUserCommand(User* user, UserCommand* usercommand);
    void execute();
};

//刪除用戶
class DeleteUserCommand : public UserCommand
{
private:
    User* user;
    UserCommand* usercommand;
public:
    DeleteUserCommand(User* user, UserCommand* usercommand);
    void execute();
};