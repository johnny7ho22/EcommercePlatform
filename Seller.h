#pragma once
#include "User.h"

class Seller:public User
{
public:
    Seller(int id, string name,int age, int role, string password);

    void showMenu(); //顯示賣家菜單
    void showProduct(); //顯示已上架商品
    void SellProduct(); //上架商品
    void showOrder(); //查看客戶訂單
    void deleteOrder(); //刪除訂單
    void confirmOrder(); //確認訂單


    ~Seller();
};