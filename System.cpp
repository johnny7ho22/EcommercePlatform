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


void System::showMenu()
{
    cout<<"歡迎登入電商平台"<<endl;
    cout<<"您要做的操作?"<<endl;
    cout<<"1.登入   2.註冊  3.離開"<<endl;
    cout<<"您的選擇 : ";
}


void System::logIn()
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

    res = stmt->executeQuery(query);
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


void System::userMainFunction()
{
    int id = res->getInt("id");
    string name = res->getString("name");
    int age = res->getInt("age");
    int role = res->getInt("role");
    string password = res->getString("password");

    User* user = userfactory->createUser(id,name,age,role,password);

    while(true)
    {
        map<int,UserCommand*> usercommands;

        usercommands.insert({
            {0, UserCommandFactory[0]->createUserCommand(user,nullptr)},
            {1, UserCommandFactory[1]->createUserCommand(user, nullptr)},
            {2, UserCommandFactory[2]->createUserCommand(user, nullptr)},
            {3, UserCommandFactory[3]->createUserCommand(user, nullptr)},
            {4, UserCommandFactory[4]->createUserCommand(user, nullptr)},
        });

        if(user->role == 1)
        {
            usercommands.insert({
                {5, UserCommandFactory[5]->createUserCommand(user,UserCommandFactory[1]->createUserCommand(user,nullptr))},
            });
        }
        else if(user->role == 2)
        {
            usercommands.insert({
                {5, UserCommandFactory[5]->createUserCommand(user,UserCommandFactory[1]->createUserCommand(user,nullptr))},
            });
        }
        else
        {
            usercommands.insert({
                {5, UserCommandFactory[5]->createUserCommand(nullptr,UserCommandFactory[1]->createUserCommand(user,nullptr))},
                {6, UserCommandFactory[6]->createUserCommand(nullptr, nullptr)},
                {7, UserCommandFactory[7]->createUserCommand(nullptr, UserCommandFactory[6]->createUserCommand(nullptr, nullptr))},
            });
        }

        usercommands[0]->execute();
        
        int choose = 0;
        cout<<"您的選擇 : ";
        cin >> choose;

    
        if(usercommands.find(choose) != usercommands.end())
        {
            usercommands[choose]->execute();
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