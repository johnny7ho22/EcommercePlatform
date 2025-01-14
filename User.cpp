#include "User.h"
   
User::User()
{
    dbconnection = DBConnection::getInstance();
    conn = dbconnection->getConnection();
}

void User::editUserInfo(User *user)
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


User::~User()
{
}