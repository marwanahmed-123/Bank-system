#pragma once
#include"Client.h"
class Employee:public Person{
protected:
    double salary = 0.0;
public:
    Employee(int id,string name,string password,double salary);
    void incrementEmployeeId();
    void addClient(Client& client);
    void editClient(int id, string name, string password, double balance);
    Client* searchClient(int id);
    void setSalary(double _salary);
    int getLastEmployeeId();
    double getSalary();
    void display() override;
};
extern vector<Employee> employees;