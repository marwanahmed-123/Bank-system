#include"FileManager.h"
#include"FilesHelper.h"
#include"Admin.h"
void FileManager::addClient(Client &c)  {
    saveClient(c);
}

void FileManager::addEmployee(Employee &e) {
    saveEmployee("employee.txt",e);
}

void FileManager::addAdmin(Admin &a) {
    saveEmployee("admin.txt",a);
}

vector<Client> FileManager::getAllClients()  {
    return clients;
}

vector<Employee> FileManager::getAllEmployees()  {
    return employees;
}

vector<Admin> FileManager::getAllAdmins() {
    return admins;
}

void FileManager::removeAllClients()  {
    clearFile("client.txt","clientLastId.txt");
    saveLast("clientLastId",0);
}

void FileManager::removeAllEmployees() {
    clearFile("employee.txt","employeeLastId.txt");
    saveLast("employeeLastId",0);
}

void FileManager::removeAllAdmins() {
    clearFile("admin.txt","adminLastId.txt");
    saveLast("adminLastId",0);
}