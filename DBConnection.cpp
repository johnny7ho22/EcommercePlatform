#include "DBConnection.h"

DBConnection* DBConnection::dbInstance = nullptr;


DBConnection::DBConnection()
{
    try 
    {
        // 初始化mysql連接驅動器
        driver = get_mysql_driver_instance();
        // 建立mysql資料庫的連接
        conn = driver->connect("tcp://127.0.0.1:3306", "root", "lin17722");
        // 設定要連接的資料庫
        conn->setSchema("ecommerce_platform");
    }
    catch (SQLException &e) 
    {
        cerr << "MySQL Error: " << e.what() << endl;
        conn = nullptr;
    }
}

DBConnection* DBConnection::getInstance()
{
    if(dbInstance == nullptr)
    {
        dbInstance = new DBConnection();
    }
    
    return dbInstance;
}

Connection*  DBConnection::getConnection()
{
    return conn;
}

DBConnection::~DBConnection()
{
    if(conn)
        delete conn;

    conn = nullptr;
}