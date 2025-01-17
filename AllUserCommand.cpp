#include "AllUserCommand.h"

ShowMenuCommand::ShowMenuCommand(User* user, UserCommand* usercommand)
{
    this->user = user;
    this->usercommand = usercommand;
}

void ShowMenuCommand::execute()
{
    user->showMenu();
}

ShowProductCommand::ShowProductCommand(User* user, UserCommand* usercommand)
{
    this->user = user;
    this->usercommand = usercommand;
}

void ShowProductCommand::execute()
{
    user->showProduct();
}


ShowOrderCommand::ShowOrderCommand(User* user, UserCommand* usercommand)
{
    this->user = user;
    this->usercommand = usercommand;
}


void ShowOrderCommand::execute()
{
    user->showOrder();
}


DeleteOrderCommand::DeleteOrderCommand(User* user, UserCommand* usercommand)
{
    this->user = user;
    this->usercommand = usercommand;
}

void DeleteOrderCommand::execute()
{
    user->deleteOrder();
}

ConfirmOrderCommand::ConfirmOrderCommand(User* user, UserCommand* usercommand)
{
    this->user = user;
    this->usercommand = usercommand;
}


void ConfirmOrderCommand::execute()
{
    user->confirmOrder();
}

EditUserInfoCommand::EditUserInfoCommand(User* user, UserCommand* usercommand)
{
    this->user = user;
    this->usercommand = usercommand;
}


void EditUserInfoCommand::execute()
{
    string name;
    int age = 0;
    int role = 0;
    string password;

    cout<<"以下是您的個人資料:"<<endl;
    cout<<"姓名 : " << user->name << "  年齡 : " << user->age
        << "  角色 : " << user->role << "  密碼 : " << user->password<<endl<<endl;
    cout<<"姓名更改為 : ";
    cin >> name;
    cout<<"年齡更改為 : ";
    cin >> age;
    cout<<"角色更改為 : ";
    cin >> role;
    cout<<"密碼更改為 : ";
    cin >> password;

    Statement* stmt = conn->createStatement();
    string query = "update users set name = '" + name + "', age = " + to_string(age) + ", role = " + to_string(role) + ", password = '" + password + "' where id =" + to_string(user->id); 
    stmt->executeUpdate(query);
}



BuyProductCommand::BuyProductCommand(User* user, UserCommand* usercommand)
{
    this->user = user;
    this->usercommand = usercommand;
}


void BuyProductCommand::execute()
{
    this->usercommand->execute();
    
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
            query = "insert into orders(uid,pid,sid,amount) values(" + to_string(this->user->id) + "," + to_string(pid) + "," + to_string(seller) + "," +  to_string(number) + ")";
            stmt->executeUpdate(query);
        }
        else
        {
            break;
        }
    }    
}

SellProductCommand::SellProductCommand(User* user, UserCommand* usercommand)
{
    this->user = user;
    this->usercommand = usercommand;
}


void SellProductCommand::execute()
{
    this->usercommand->execute();

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
            string query = "insert into products(name, price, description, seller) values('" + name + "'," + to_string(price) + ", '" + description + "'," + to_string(this->user->id) +")" ;
            stmt->executeUpdate(query);
        }
        else
        {
            break;
        }
    }
}

DeleteProductCommand::DeleteProductCommand(User* user, UserCommand* usercommand)
{
    this->user = user;
    this->usercommand = usercommand;
}


void DeleteProductCommand::execute()
{
    this->usercommand->execute();

    while(true)
    {
        int choose = 0;
        cout<<"您要做的操作: 1.刪除商品 2.離開"<<endl;
        cout<<"您的選擇:";
        cin >>choose;

        if(choose == 1)
        {
            int id;

            cout<<"您要刪除的商品 : ";
            cin >> id;

            Statement* stmt = conn->createStatement();
            string query = "delete from products where id = " + to_string(id);
            stmt->executeUpdate(query);
        }
        else
        {
            break;
        }
    }    
}

ShowUserCommand::ShowUserCommand(User* user, UserCommand* usercommand)
{
    this->user = user;
    this->usercommand = usercommand;
}


void ShowUserCommand::execute()
{
    Statement* stmt = conn->createStatement();

    string query = "select * from users";

    ResultSet* res = stmt->executeQuery(query);

    cout<<"所有用戶"<<endl;
    cout << "ID\tName\tAge\tRole\tPassword"<<endl;

    while(res->next())
    {
        cout << res->getInt("id") << "\t" << res->getString("name") << "\t"
             << res->getInt("age") << "\t" << res->getInt("role") << "\t" 
             << res->getString("password") <<endl;
    }

    cout<<endl;
}

DeleteUserCommand::DeleteUserCommand(User* user, UserCommand* usercommand)
{
    this->user = user;
    this->usercommand = usercommand;
}


void DeleteUserCommand::execute()
{
    this->usercommand->execute();

    while(true)
    {
        int choose = 0;
        
        cout<<"您要做的操作 : 1.刪除用戶 2.離開"<<endl;
        cout<<"您的選擇:";
        cin >>choose;

        if(choose == 1)
        {
            int id = 0;//選擇的用戶編號
            
            cout<<"選擇你要刪除的用戶 : ";
            cin >> id;

            Statement* stmt = conn->createStatement();
            string query = "delete from users where id =" + to_string(id); 
            stmt->executeUpdate(query);
        }
        else
        {
            break;
        }
   
    }   
}