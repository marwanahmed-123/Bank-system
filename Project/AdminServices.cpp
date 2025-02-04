#include"AdminServices.h"
Employee *AdminServices::searchEmployee(int id){
    for (auto i = employees.begin(); i != employees.end(); ++i) {
        if (id == i->getId()) {
            return &*i;
        }
    }
    return nullptr;
}

Admin *AdminServices::searchAdmin(int id){
    for (auto i = admins.begin(); i != admins.end(); ++i) {
        if (id == i->getId()) {
            return &*i;
        }
    }
    return nullptr;
}

void AdminServices::editEmployee(int id, std::string name, std::string password, double salary){
    for (auto i = employees.begin(); i != employees.end() ; ++i) {
        if (i->getId()==id) {
            i->setName(name);
            i->setPassword(password);
            i->setSalary(salary);
            return;
        }
    }
}

void AdminServices::listEmployees(){
    for (auto i = employees.begin(); i != employees.end() ; ++i) {
        cout<<i->getId()
            <<endl<<i->getName()
            <<endl<<i->getPassword()
            <<endl<<i->getSalary()<<endl;
    }
}