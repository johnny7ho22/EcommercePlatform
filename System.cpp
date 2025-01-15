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

            user->userMainFunction();

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
    cout<<"您是 1.買家 or 2.賣家"<<endl;
    cout<<"您的選擇 : "; 
    cin >> role;
    cout<<"輸入密碼 : "<<endl;
    cin >> password;
    

    Statement* stmt = conn->createStatement(); //創建SQL查詢語句
    
    string query = "INSERT INTO users (name,age,role,password) VALUES ('" + name + "', " + to_string(age) + "," + to_string(role) +",'" + password +"')";

    stmt->executeUpdate(query);
}





System::~System()
{
    if(sys) 
    {
        delete sys;
    }

    sys = nullptr;
}