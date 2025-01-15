#include "Seller.h"

Seller::Seller(int id, string name,int age, int role, string password)
{
    this->id = id;
    this->name = name;
    this->age = age;
    this->role = role;
    this->password = password;
}

//這個部分可以透過command pattern來設計
void Seller::userMainFunction()
{
    system("clear");

    while(true)
    {
        int choose = 0;
        cout<<"1.顯示已上架商品 2.上架商品 3.查看買家訂單 4.刪除訂單 5. 確定訂單 6.修改個人資訊 7.離開"<<endl;
        cout<<"您的選擇 : ";
        cin >> choose;

        if(choose == 1) 
        {
            showProduct();
        }
        else if(choose == 2)
        {
            SellProduct();
        }
        else if(choose == 3)
        {
            showOrder();
        }
        else if(choose == 4)
        {
            deleteOrder();
        }
        else if(choose == 5)
        {
            confirmOrder();
        }
        else if(choose == 6)
        {
            editUserInfo(this);
        }
        else
        {
            system("clear");
            break;
        }

        // 當你用 cin >> choose; 讀取用戶輸入時，choose 會被賦予一個值，但按下回車後，緩衝區中仍然有一個換行符 '\n'，
        //這會被 std::cin.get() 讀取並立即返回，導致它沒有真正等待用戶按任意鍵。
        //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 是用來清除緩衝區中的多餘字符（包括換行符），
        //這樣在隨後的 std::cin.get() 時能正確等待用戶按任意鍵。
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        cout << "\n輸入任意鍵以繼續..." << std::endl;
        std::cin.get();  // 等待用戶按下任意鍵
        system("clear");
    }
}


void Seller::showProduct()
{
    Statement* stmt = conn->createStatement();

    string query = "select * from products where seller =" + to_string(this->id);

    ResultSet* res = stmt->executeQuery(query);

    cout<<"您已上架的商品"<<endl;

    cout << "ID\tName\tPrice\tDescription\tSeller"<<endl;

    while(res->next())
    {
        cout << res->getInt("id") << "\t" << res->getString("name") << "\t"
             << res->getInt("price") << "\t" << res->getString("description")
             << "\t" << res->getInt("seller") <<endl;
    }
    cout<<endl;
}

void Seller::SellProduct()
{
    showProduct();

    while(true)
    {
        int choose = 0;
        cout<<"您要做的操作: 1.上架商品 2.離開"<<endl;
        cout<<"您的選擇:";
        cin >>choose;

        if(choose == 1)
        {
            string name;
            int price;
            string description;

            cout<<"商品名稱 : ";
            cin >> name;
            cout<<"定價 : ";
            cin >> price;
            cout<<"商品描述 : ";
            cin >> description;

            Statement* stmt = conn->createStatement();
            string query = "insert into products(name, price, description, seller) values('" + name + "'," + to_string(price) + ", '" + description + "'," + to_string(this->id) +")" ;
            stmt->executeUpdate(query);
        }
        else
        {
            break;
        }
    }    
}

void Seller::showOrder()
{
    Statement* stmt = conn->createStatement();
    string query = "select * from orders where sid =" + to_string(this->id) + " order by uid";
    ResultSet* res = stmt->executeQuery(query);


    cout<<"以下為買家的訂單:"<<endl;
    cout << "ID\tBuyer\tProduct\tAmount\tStatus"<<endl;
    
    while(res->next())
    {
        int id = res->getInt("id");
        string buyer;
        string product;
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


        cout << id << "\t" 
             << buyer << "\t" 
             << product << "\t" 
             << amount << "\t" 
             << status <<endl;
    }
    cout<<endl;
}

void Seller::deleteOrder()
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

void Seller::confirmOrder()
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
            int status_choose = 0; //選擇的物流方式
            string status; //支付方式
            
            cout<<"選擇你要確認的訂單 : ";
            cin >> id;
            cout<<"選擇物流方式: 1.海運 2.空運 3. 公路運輸"<<endl;
            cout<<"您的選擇:";
            cin >> status_choose;

            if(status_choose == 1)
                status = "海運";
            else if(status_choose == 2)
                status = "空運";
            else
                status = "公路運輸";
            

            Statement* stmt = conn->createStatement();
            string query = "update orders set status = '" + status + "' where id =" + to_string(id); 
            stmt->executeUpdate(query);
        }
        else
        {
            break;
        }
   
    }
}

Seller::~Seller()
{

}