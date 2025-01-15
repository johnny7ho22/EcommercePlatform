#pragma once
#include "User.h"

class Admin:public User
{
public:
    Admin(int id, string name,int age, int role, string password);

    void showMenu(); //顯示管理員菜單
    void showProduct(); //顯示商品
    void showOrder(); //查看訂單
    void deleteOrder(); //刪除訂單
    void confirmOrder(); //確認訂單

    ~Admin();
};