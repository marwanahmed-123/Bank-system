#pragma once
#include"Employee.h"
using namespace std;
class EmployeeFunctions{
protected:
    static void newClient(Employee* employee);
    static void listAllClients(Employee* employee);
    static Client* searchForClient(Employee* employee);
    static void editClientInfo(Employee* employee);
};