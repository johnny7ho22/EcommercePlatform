#include "AllUserCommandFactory.h"
#include "AllUserCommand.h"


UserCommand* ShowMenuCommandFactory::createUserCommand(User* user, UserCommand* usercommand)
{
    return new ShowMenuCommand(user,nullptr);
}


//顯示商品
UserCommand* ShowProductCommandFactory::createUserCommand(User* user, UserCommand* usercommand)
{
    return new ShowProductCommand(user,nullptr);
};


//顯示訂單
UserCommand* ShowOrderCommandFactory::createUserCommand(User* user, UserCommand* usercommand)
{
    return new ShowOrderCommand(user,nullptr);
};


//刪除訂單
UserCommand* DeleteOrderCommandFactory::createUserCommand(User* user, UserCommand* usercommand)
{
    return new DeleteOrderCommand(user,nullptr);
};


//確認訂單
UserCommand* ConfirmOrderCommandFactory::createUserCommand(User* user, UserCommand* usercommand)
{
    return new ConfirmOrderCommand(user,nullptr);
};


//修改個人資訊
UserCommand* EditUserInfoCommandFactory::createUserCommand(User* user, UserCommand* usercommand)
{
    return new EditUserInfoCommand(user,nullptr);
};


// 購買商品
UserCommand* BuyProductCommandFactory::createUserCommand(User* user, UserCommand* usercommand)
{
    return new BuyProductCommand(user,usercommand);
};


//上架商品
UserCommand* SellProductCommandFactory::createUserCommand(User* user, UserCommand* usercommand)
{
    return new SellProductCommand(user,usercommand);
};


//刪除商品
UserCommand* DeleteProductCommandFactory::createUserCommand(User* user, UserCommand* usercommand)
{
    return new DeleteProductCommand(nullptr,usercommand);
};


//查看用戶
UserCommand* ShowUserCommandFactory::createUserCommand(User* user, UserCommand* usercommand)
{
   return new ShowUserCommand(nullptr,nullptr);
};


//刪除用戶
UserCommand* DeleteUserCommandFactory::createUserCommand(User* user, UserCommand* usercommand)
{
    return new DeleteUserCommand(nullptr,usercommand);
};