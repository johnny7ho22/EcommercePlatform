#pragma once
#include "User.h"

class Admin:public User
{
public:
    Admin(int id, string name,int age, int role, string password);

    void userMainFunction(); //用戶主功能

    void showProduct(); //顯示商品
    void deleteProduct(); //刪除商品

    void showOrder(); //查看訂單
    void deleteOrder(); //刪除訂單
    void confirmOrder(); //確認訂單

    void showUser(); //查看用戶
    void deleteUser(); //刪除用戶
    

    ~Admin();
};