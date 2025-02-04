#include "Employee.h"
#include"FileManager.h"
#include"EmployeeServices.h"
Employee::Employee(int id,std::string name, std::string password, double _salary):
Person(id,name,password) {
    salary=_salary;
}
void Employee::addClient(Client &client) {
    FileManager::addClient(client);
}
void Employee::editClient(int id, std::string name, std::string password, double balance){
    EmployeeServices::editClient(id,name,password,balance);
}
Client *Employee::searchClient(int id){
    return EmployeeServices::searchClient(id);
}
void Employee::setSalary(double _salary) {
    salary =_salary;
}
double Employee::getSalary() {
    return salary;
}
void Employee::display() {
    cout<<"ID: "<<this->getId()
        <<endl<<"Name: "<<this->getName()
        <<endl<<"Password: "<<this->getPassword()
        <<endl<<"Salary: "<<salary<<endl;
}
vector<Employee> employees;