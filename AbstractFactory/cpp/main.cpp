
#include "employee.h"

int main() {
    EmployeeDAO* dao = new EmployeeDAO();
    dao->SetDB(new OracleDBFactory());
    dao->GetEmployees();

    std::cout << std::endl;

    dao->SetDB(new SqlDBFactory());
    dao->GetEmployees();

    return EXIT_SUCCESS;
}