#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include <iostream>
#include <vector>

#include "db.h"

class EmployeeDO {};

class EmployeeDAO {
public:
    EmployeeDAO() {}

    void SetDB(IDBFactory* _dbFactory) { this->dbFactory = _dbFactory; }

    std::vector<EmployeeDO*> GetEmployees() {
        IDBConnection* dbConn = dbFactory->CreateDBConnection();
        IDBCommand* dbCmd = dbFactory->CreateDBCommand();
        IDataReader* reader = dbFactory->CreateDataReader();

        // business logic...

        return std::vector<EmployeeDO*>();
    }

private:
    IDBFactory* dbFactory;
};

#endif // __EMPLOYEE_H__