#pragma once
#include "EmployeeFunctionalitiesForScreen.h"
#include"Admin.h"
using namespace std;
class AdminManager: protected EmployeeFunctions{
private:
    static void printAdminOptions();
    static void newEmployee(Admin* admin);
    static Employee* searchForEmployee(Admin* admin);
public:
    static Admin* login(int id, string password);
    static bool adminOptions(Admin* admin);
};