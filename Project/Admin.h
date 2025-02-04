#pragma once
#include"Employee.h"
using namespace std;
class Admin:public Employee{
public:
    Admin(int id,string name,string password,double salary);
    void incrementAdminId();
    int getLastAdminId();
    void addEmployee(Employee& employee);
    Employee* searchEmployee(int id);
    Admin* searchAdmin(int id);
};
extern vector<Admin> admins;