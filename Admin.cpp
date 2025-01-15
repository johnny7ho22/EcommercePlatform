#include "Admin.h"

Admin::Admin(int id, string name,int age, int role, string password)
{
    this->id = id;
    this->name = name;
    this->age = age;
    this->role = role;
    this->password = password;
}


void Admin::showMenu()
{
    cout<<"1.查看商品 2.刪除商品 3.查看訂單 4.刪除訂單 5. 確認訂單 6.查看用戶 7.刪除用戶 8.修改個人資訊 9.離開"<<endl;
}


void Admin::showProduct()
{
    Statement* stmt = conn->createStatement();

    string query = "select * from products order by seller";

    ResultSet* res = stmt->executeQuery(query);


    cout<<"所有商品"<<endl;

    cout << "ID\tName\tPrice\tDescription\tSeller"<<endl;

    while(res->next())
    {
        string seller;
        ResultSet* res2 = nullptr;

        //取得賣家名稱
        query = "select name from users where id =" + to_string(res->getInt("seller"));

        res2 = stmt->executeQuery(query);

        if(res2->next())
            seller = res2->getString("name");

        cout << res->getInt("id") << "\t" << res->getString("name") << "\t"
             << res->getInt("price") << "\t" << res->getString("description")
             << "\t" << seller <<endl;
    }

    cout<<endl;
}


void Admin::showOrder()
{
    Statement* stmt = conn->createStatement();
    string query = "select * from orders";
    ResultSet* res = stmt->executeQuery(query);


    cout<<"所有訂單:"<<endl;
    cout << "ID\tBuyer\tProduct\tSeller\tAmount\tStatus"<<endl;
    
    while(res->next())
    {
        int id = res->getInt("id");
        string buyer;
        string product;
        string seller;
        int amount = res->getInt("amount");
        string status = res->getString("status");

        ResultSet* res2 = nullptr;

        //取得買家名稱
        query = "select name from users where id =" + to_string(res->getInt("uid"));
        res2 = stmt->executeQuery(query);
        if(res2->next())
            buyer = res2->getString("name");

        //取得商品名稱
        query = "select name from products where id =" + to_string(res->getInt("pid"));     
        res2 = stmt->executeQuery(query);
        if(res2->next())
            product = res2->getString("name");

        //取得賣家名稱
        query = "select name from users where id =" + to_string(res->getInt("sid"));
        res2 = stmt->executeQuery(query);
        if(res2->next())
        seller = res2->getString("name");


        cout << id << "\t" 
             << buyer << "\t" 
             << product << "\t"
             << seller << "\t" 
             << amount << "\t" 
             << status <<endl;
    }
    cout<<endl;
}

void Admin::deleteOrder()
{
    showOrder();
 
    while(true)
    {
        int choose = 0;
        
        cout<<"您要做的操作 : 1.刪除訂單 2.離開"<<endl;
        cout<<"您的選擇:";
        cin >>choose;

        if(choose == 1)
        {
            int id = 0;//選擇的訂單編號
            cout<<"選擇你要刪除的訂單 : ";
            cin >> id;

            Statement* stmt = conn->createStatement();
            string query = "delete from orders where id =" + to_string(id);
            stmt->executeUpdate(query);
        }
        else
        {
            break;
        }
    }    
}

void Admin::confirmOrder()
{
    showOrder();

    while(true)
    {
        int choose = 0;
        
        cout<<"您要做的操作 : 1.確認訂單 2.離開"<<endl;
        cout<<"您的選擇:";
        cin >>choose;

        if(choose == 1)
        {
            int id = 0;//選擇的訂單編號
            
            cout<<"選擇你要確認的訂單 : ";
            cin >> id;

            Statement* stmt = conn->createStatement();
            string query = "update orders set status = '訂單完成' where id =" + to_string(id); 
            stmt->executeUpdate(query);
        }
        else
        {
            break;
        }
   
    }
}

Admin::~Admin()
{

}