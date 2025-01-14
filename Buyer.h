#pragma once
#include "User.h"

class Buyer:public User
{
public:
    Buyer(int id, string name,int age, int role, string password);

    void userMainFunction(); //買家主功能
    void showAllProduct(); //顯示所有商品
    void buyProduct(); //購買商品
    void showOrder(); //查看訂單
    void deleteOrder(); //刪除訂單
    void confirmOrder(); //確認訂單


    ~Buyer();
};