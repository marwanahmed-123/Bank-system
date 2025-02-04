#pragma once
#include"EmployeeFunctionalitiesForScreen.h"
using namespace std;
class EmployeeManager:protected EmployeeFunctions{
private:
    static void printEmployeeMenu() ;
public:
    static Employee* login(int id, string password);
    static bool employeeOptions(Employee* employee);
};