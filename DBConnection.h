#pragma once

#include <mysql_driver.h> //包含mysql驅動程式的相關接口
#include <mysql_connection.h> //提供和mysql連線的接口，包括建立連線和執行sql查詢

using namespace sql;
using namespace mysql;
using namespace std;


#include <stdexcept> //用來捕獲和處理標準異常

class DBConnection 
{
private:
    MySQL_Driver *driver;
    Connection *conn;
    static DBConnection *dbInstance; //靜態變數屬於類本身，意味著無論有多少個物件存在，靜態變數都只有一個，它的值對所有物件共享

    //將建構子設為私有，這樣可以防止外部直接創建
    DBConnection();

    DBConnection(const DBConnection &) = delete;
    DBConnection& operator=(const DBConnection &) = delete;

public:
    static DBConnection* getInstance(); //取得單一物件
    Connection* getConnection(); //取得連接
    ~DBConnection(); //清理資源
};
