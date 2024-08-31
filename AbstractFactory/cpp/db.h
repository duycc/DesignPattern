#ifndef __ABSTRACT_FACTORY_H__
#define __ABSTRACT_FACTORY_H__

#include <iostream>

// 数据库访问有关的基类
class IDBConnection {};

class IDBCommand {};

class IDataReader {};

class IDBFactory {
public:
    virtual IDBConnection* CreateDBConnection() = 0;
    virtual IDBCommand* CreateDBCommand() = 0;
    virtual IDataReader* CreateDataReader() = 0;
};

// 支持 SQL Server
class SqlConnection : public IDBConnection {
public:
    SqlConnection() { std::cout << "create SQLDB connection..." << std::endl; }
};
class SqlCommand : public IDBCommand {
public:
    SqlCommand() { std::cout << "create SQLDB command..." << std::endl; }
};
class SqlDataReader : public IDataReader {
public:
    SqlDataReader() { std::cout << "create SQLDB reader..." << std::endl; }
};

class SqlDBFactory : public IDBFactory {
public:
    SqlDBFactory() { std::cout << "use SQLDB client..." << std ::endl; }

    IDBConnection* CreateDBConnection() { return new SqlConnection(); }

    IDBCommand* CreateDBCommand() { return new SqlCommand(); }

    IDataReader* CreateDataReader() { return new SqlDataReader(); }
};

// 支持 Oracle
class OracleConnection : public IDBConnection {
public:
    OracleConnection() { std::cout << "create Oracle connection..." << std::endl; }
};
class OracleCommand : public IDBCommand {
public:
    OracleCommand() { std::cout << "create Oracle command..." << std::endl; }
};
class OracleDataReader : public IDataReader {
public:
    OracleDataReader() { std::cout << "create Oracle reader..." << std::endl; }
};

class OracleDBFactory : public IDBFactory {
public:
    OracleDBFactory() { std::cout << "use OracleDB client..." << std::endl; }

    IDBConnection* CreateDBConnection() { return new OracleConnection(); }

    IDBCommand* CreateDBCommand() { return new OracleCommand(); }

    IDataReader* CreateDataReader() { return new OracleDataReader(); }
};

#endif // __ABSTRACT_FACTORY_H__