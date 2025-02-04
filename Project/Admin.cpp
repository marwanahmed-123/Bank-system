#include<iostream>
#include"Admin.h"
#include "FileManager.h"
#include"AdminServices.h"
using namespace std;
Admin::Admin(int id,string name,string password,double salary):Employee(id,name,password,salary){}
void Admin::addEmployee(Employee &employee) {
    FileManager::addEmployee(employee);
}
Employee* Admin::searchEmployee(int id) {
    return AdminServices::searchEmployee(id);
}
Admin* Admin::searchAdmin(int id) {
    return AdminServices::searchAdmin(id);
}
vector<Admin> admins;