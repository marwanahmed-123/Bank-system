#include"Person.h"
Person::Person(int id,std::string name, std::string password):id(id),name(name),password(password){}

void Person::setName(std::string &_name) {
    name = _name;
}

void Person::setId(int _id) {
    id=_id;
}

string Person::getName() {
    return name;
}

void Person::setPassword(std::string &pass) {
    password=pass;
}

string Person::getPassword() {
    return password;
}
int Person::getId() {
    return id;
}