#pragma once
#include"Client.h"
#include"Employee.h"
#include"Admin.h"
using namespace std;
using namespace std;
class FileManager{
public:
    static void addClient (Client& c);
    static void addEmployee(Employee& e);
    static void addAdmin(Admin& a);
    static vector<Client> getAllClients ();
    static vector<Employee> getAllEmployees ();
    static vector<Admin> getAllAdmins ();
    static void removeAllClients ();
    static void removeAllEmployees ();
    static void removeAllAdmins ();
};