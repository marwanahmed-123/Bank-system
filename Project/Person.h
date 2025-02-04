#pragma once
#include<iostream>
using namespace std;
class Person{
private:
    string name,password;
    int id=0;
public:
    Person(int id,string name,string password);
    void setName(string& _name);
    void setId(int _id);
    int getId();
    string getName();
    void setPassword(string& pass);
    string getPassword();
    virtual void display()=0;
};