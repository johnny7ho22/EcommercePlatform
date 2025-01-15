#include "Buyer.h"

Buyer::Buyer(int id, string name,int age, int role, string password)
{
    this->id = id;
    this->name = name;
    this->age = age;
    this->role = role;
    this->password = password;
}

//這個部分可以透過command pattern來設計
void Buyer::userMainFunction()
{
    while(true)
    {
        int choose = 0;
        cout<<"1.查看所有商品 2.購買商品 3.查看訂單 4.刪除訂單 5. 確認訂單 6.修改個人資訊 7.離開"<<endl;
        cout<<"您的選擇 : ";
        cin >> choose;

        if(choose == 1) 
        {
            showProduct();
        }
        else if(choose == 2)
        {
            buyProduct();

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


void Buyer::showProduct()
{
    Statement* stmt = conn->createStatement();

    string query = "select * from products order by seller;";

    ResultSet* res = stmt->executeQuery(query);

    cout << "ID\tName\tPrice\tDescription\tSeller"<<endl;

    while(res->next())
    {
        cout << res->getInt("id") << "\t" << res->getString("name") << "\t"
             << res->getInt("price") << "\t" << res->getString("description")
             << "\t" << res->getInt("seller") <<endl;
    }
    cout<<endl;
}

void Buyer::buyProduct()
{
    
    showProduct();
    
    while(true)
    {
        int choose = 0;
        cout<<"您要做的操作: 1.消費 2.離開"<<endl;
        cout<<"您的選擇:";
        cin >>choose;

        if(choose == 1)
        {
            int pid = 0;
            int number = 0;

            cout<<"您要購買的商品 : ";
            cin >> pid;
            cout<<"您要多少數量 : ";
            cin >> number;

            Statement* stmt = conn->createStatement();
            //取得seller的id
            string query = "select seller from products where id =" + to_string(pid);
            ResultSet* res = stmt->executeQuery(query);
            int seller = 0;

            if(res->next())
            {
                seller = res->getInt("seller");
            }

            //加入訂單
            query = "insert into orders(uid,pid,sid,amount) values(" + to_string(this->id) + "," + to_string(pid) + "," + to_string(seller) + "," +  to_string(number) + ")";
            stmt->executeUpdate(query);
        }
        else
        {
            break;
        }
    }    
}

void Buyer::showOrder()
{
    Statement* stmt = conn->createStatement();
    string query = "select * from orders where uid =" + to_string(this->id);
    ResultSet* res = stmt->executeQuery(query);


    cout<<"以下為您的訂單:"<<endl;
    cout << "ID\tProduct\tSeller\tAmount\tStatus"<<endl;
    
    while(res->next())
    {
        int id = res->getInt("id");
        string product;
        string seller;
        int amount = res->getInt("amount");
        string status = res->getString("status");

        ResultSet* res2 = nullptr;

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
             << product << "\t" 
             << seller << "\t" 
             << amount << "\t" 
             << status <<endl;
    }
    cout<<endl;
}

void Buyer::deleteOrder()
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

void Buyer::confirmOrder()
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
            int status_choose = 0; //選擇的支付方式
            string status; //支付方式
            
            cout<<"選擇你要確認的訂單 : ";
            cin >> id;
            cout<<"選擇支付方式: 1.信用卡支付 2.現金支付 3.Line Pay"<<endl;
            cout<<"您的選擇:";
            cin >> status_choose;

            if(status_choose == 1)
                status = "信用卡支付";
            else if(status_choose == 2)
                status = "現金支付";
            else
                status = "Line Pay支付";
            

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

Buyer::~Buyer()
{

}