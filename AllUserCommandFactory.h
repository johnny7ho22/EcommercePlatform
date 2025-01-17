#pragma once
#include "UserCommandFactory.h"


//顯示菜單
class ShowMenuCommandFactory : public UserCommandFactory 
{
public:
    UserCommand* createUserCommand(User* user, UserCommand* usercommand);
};


//顯示商品
class ShowProductCommandFactory : public UserCommandFactory
{
public:
    UserCommand* createUserCommand(User* user, UserCommand* usercommand);
};


//顯示訂單
class ShowOrderCommandFactory : public UserCommandFactory
{
public:
    UserCommand* createUserCommand(User* user, UserCommand* usercommand);
};


//刪除訂單
class DeleteOrderCommandFactory : public UserCommandFactory
{
public:
    UserCommand* createUserCommand(User* user, UserCommand* usercommand);
};


//確認訂單
class ConfirmOrderCommandFactory : public UserCommandFactory
{
public:
    UserCommand* createUserCommand(User* user, UserCommand* usercommand);
};


//修改個人資訊
class EditUserInfoCommandFactory : public UserCommandFactory
{
public:
    UserCommand* createUserCommand(User* user, UserCommand* usercommand);
};


// 購買商品
class BuyProductCommandFactory : public UserCommandFactory
{
public:
    UserCommand* createUserCommand(User* user, UserCommand* usercommand);
};


//上架商品
class SellProductCommandFactory : public UserCommandFactory
{
public:
    UserCommand* createUserCommand(User* user, UserCommand* usercommand);
};


//刪除商品
class DeleteProductCommandFactory : public UserCommandFactory
{
public:
    UserCommand* createUserCommand(User* user, UserCommand* usercommand);
};


//查看用戶
class ShowUserCommandFactory : public UserCommandFactory
{
public:
    UserCommand* createUserCommand(User* user, UserCommand* usercommand);
};


//刪除用戶
class DeleteUserCommandFactory : public UserCommandFactory
{
public:
    UserCommand* createUserCommand(User* user, UserCommand* usercommand);
};
