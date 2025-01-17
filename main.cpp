#include <iostream>
// #include <cppconn/resultset.h> //這是 C++ Connector 用來處理 SQL 查詢結果的標頭文件。
// #include <cppconn/statement.h>
#include <string>


#include "System.h"

//用戶相關
#include "Buyer.h"
#include "Seller.h"
#include "Admin.h"
#include "AllUserFactory.h"

//用戶指令相關
#include "AllUserCommand.h"
#include "AllUserCommandFactory.h"

using namespace std;
using namespace sql;
using namespace mysql;



int main() 
{
    System* sys = System::getInstance();
    User* user = nullptr;

    while(true)
    {
        sys->showMenu();

        int choose = 0;
        cin >>choose;

        if(choose == 1) //登入
        {
            sys->logIn();

            system("clear");

            if(sys->res->next())
            {   
                int role = sys->res->getInt("role");

                sys->UserCommandFactory.erase(5);

                sys->UserCommandFactory.insert({
                    {0, new ShowMenuCommandFactory()},
                    {1, new ShowProductCommandFactory()},
                    {2, new ShowOrderCommandFactory()},
                    {3, new DeleteOrderCommandFactory()},
                    {4, new ConfirmOrderCommandFactory()},
                });

                if(role == 1) 
                {
                    sys->userfactory = new BuyerFactory();
                    sys->UserCommandFactory.insert({5, new BuyProductCommandFactory()});

                }
                else if(role == 2)
                {
                    sys->userfactory = new SellerFactory();
                    sys->UserCommandFactory.insert({5, new SellProductCommandFactory()});

                }
                else
                {
                    sys->userfactory = new AdminFactory();
                    sys->UserCommandFactory.insert({
                        {5, new DeleteProductCommandFactory()},
                        {6, new ShowUserCommandFactory()},
                        {7,new DeleteUserCommandFactory()}
                    });
                }

                sys->userMainFunction();
            }
            else
            {
                
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

                cout<<"此用戶不存在"<<endl;
                cout << "\n輸入任意鍵以繼續..." << std::endl;
                std::cin.get();  // 等待用戶按下任意鍵

                system("clear");

            }
        }
        else if(choose == 2) //註冊
        {
            sys->signUp();
            system("clear");
        }
        else
        {
            break;
        }
    }

    return 0;
}