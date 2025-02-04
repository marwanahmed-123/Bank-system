#pragma once
#include"Person.h"
#include<vector>
#include"BalanceServices.h"
class Client:public Person{
private:
    double balance=0.0;
public:
    Client(int id,string name,string password,double _balance);
    void setBalance(double _balance);
    double getBalance();
    void displayBalance();
    bool withDraw(double amount);
    void desposit(double amount);
    bool transferTo(double amount,Client& recipient);
    void display() override;
};
extern vector<Client> clients;