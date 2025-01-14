#include <iostream>
// #include <cppconn/resultset.h> //這是 C++ Connector 用來處理 SQL 查詢結果的標頭文件。
// #include <cppconn/statement.h>
#include <string>


#include "System.h"



using namespace std;
using namespace sql;
using namespace mysql;



int main() 
{


    System* sys = System::getInstance();
    sys->start();
    

    return 0;
}


// //獲取DBConnection的單例實例
//     DBConnection* dbconnection = DBConnection::getInstance();
    
//     //取得MySQL連接
//     Connection* conn = dbconnection->getConnection();

//     if(conn)
//     {
//         //創建SQL查詢語句
//         Statement *stmt = conn->createStatement();
//         ResultSet *res = stmt->executeQuery("select * from users");

//         while(res->next())
//         {
//             cout << "ID: " << res->getInt("id") << ", Name: " << res->getString("name") << endl;
//         }

//         delete res;
//         delete stmt;
//     }
//     else
//     {
//         cout<<"連接失敗"<<endl;
//     }