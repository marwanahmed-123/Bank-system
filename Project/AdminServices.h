#pragma once
#include <iostream>
#include "Employee.h"
#include"Admin.h"
using namespace std;
class AdminServices{
public:
    static Employee* searchEmployee(int id);
    static Admin* searchAdmin(int id);
    static void editEmployee(int id, string name, string password, double salary);
    static void listEmployees();
};