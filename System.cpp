#include "System.h"

using namespace std;

System* System::sys = nullptr;

System::System()
{
    dbconnection = DBConnection::getInstance(); //獲取DBConnection的單例實例
    conn = dbconnection->getConnection(); //取得MySQL連接
}


System* System::getInstance()
{
    if(sys == nullptr)
    {
        sys = new System();
    }

    return sys;
}


void System::start()
{

    while(true)
    {
        int choose = 0;
        User* user = nullptr;

        cout<<"歡迎登入電商平台"<<endl;
        cout<<"您要做的操作?"<<endl;
        cout<<"1.登入   2.註冊  3.離開"<<endl;
        cout<<"您的選擇 : ";
        cin >>choose;

        
        if(choose == 1)
        {
            user = logIn();
            
            system("clear");

            userMainFunction(user);

        }
        else if(choose == 2)
        {
            signUp();
            system("clear");
        }
        else
        {
            break;
        }
    }
}


User* System::logIn()
{
    string name;
    string password;
    User* user = nullptr;


    cout<<"您的名字 : ";
    cin >> name;
    cout<<"您的密碼 : ";
    cin >> password;

    Statement* stmt = conn->createStatement(); //創建SQL查詢語句
    
    string query = "Select * from users where name = '" + name + "'" + "and password = '" +password + "'";

    ResultSet* res = stmt->executeQuery(query);

    if(res->next())
    {
        int id = res->getInt("id");
        string name = res->getString("name");
        int age = res->getInt("age");
        int role = res->getInt("role");
        string password = res->getString("password");

        if(role == 1)
        {
            user = new Buyer(id, name, age, role, password);
        }
        else if(role == 2)
        {
            user = new Seller(id, name, age, role, password);
        }
        else
        {
            user = new Admin(id, name, age, role, password);
        }
    }
    else
    {
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

        cout<<"此用戶不存在"<<endl;
        cout << "\n輸入任意鍵以繼續..." << std::endl;
        std::cin.get();  // 等待用戶按下任意鍵

        system("clear");
    }
    
    return user;

}

void System::signUp()
{
    string name;
    int age = 0;
    int role = 0;
    string password;

    cout<<"您的姓名 : ";
    cin >> name;
    cout<<"您的年齡 : ";
    cin >> age;
    cout<<"您是 1.買家 or 2.賣家 or 3.管理員"<<endl;
    cout<<"您的選擇 : "; 
    cin >> role;
    cout<<"輸入密碼 : "<<endl;
    cin >> password;
    

    Statement* stmt = conn->createStatement(); //創建SQL查詢語句
    
    string query = "INSERT INTO users (name,age,role,password) VALUES ('" + name + "', " + to_string(age) + "," + to_string(role) +",'" + password +"')";

    stmt->executeUpdate(query);
}


void System::userMainFunction(User* user)
{
    map<int,Command*> commands;

    if(user->role == 1)
    {
        commands = {
            {1, new ShowProductCommand(user)},
            {2, new BuyProductCommand(new ShowProductCommand(user), user->id)},
            {3, new ShowOrderCommand(user)},
            {4, new DeleteOrderCommand(user)},
            {5, new ConfirmOrderCommand(user)},
            {6, new EditUserInfo(user)}
        };
    }
    else if(user->role == 2)
    {
        commands = {
            {1, new ShowProductCommand(user)},
            {2, new SellProductCommand(new ShowProductCommand(user), user->id)},
            {3, new ShowOrderCommand(user)},
            {4, new DeleteOrderCommand(user)},
            {5, new ConfirmOrderCommand(user)},
            {6, new EditUserInfo(user)}
        };
    }
    else
    {        
        commands = {
            {1, new ShowProductCommand(user)},
            {2, new DeleteProductCommand(new ShowProductCommand(user))},
            {3, new ShowOrderCommand(user)},
            {4, new DeleteOrderCommand(user)},
            {5, new ConfirmOrderCommand(user)},
            {6, new ShowUserCommand()},
            {7,new DeleteUserCommand(new ShowUserCommand())},
            {8, new EditUserInfo(user)}
        };
    }

    while(true)
    {
        Command* showMenuCommand = new ShowMenuCommand(user);
        showMenuCommand->execute();
        
        int choose = 0;
        cout<<"您的選擇 : ";
        cin >> choose;

    

        if(commands.find(choose) != commands.end())
        {
            commands[choose]->execute();
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


System::~System()
{
    if(sys) 
    {
        delete sys;
    }

    sys = nullptr;
}