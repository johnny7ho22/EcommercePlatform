#include <iostream>
// #include <cppconn/resultset.h> //這是 C++ Connector 用來處理 SQL 查詢結果的標頭文件。
// #include <cppconn/statement.h>
#include <string>


#include "System.h"
#include "Buyer.h"
#include "Seller.h"
#include "Admin.h"
#include "BuyerFactory.h"
#include "SellerFactory.h"
#include "AdminFactory.h"



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

                if(role == 1) 
                {
                    sys->userfactory = new BuyerFactory();
                }
                else if(role == 2)
                {
                    sys->userfactory = new BuyerFactory();
                }
                else
                {
                    sys->userfactory = new BuyerFactory();
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