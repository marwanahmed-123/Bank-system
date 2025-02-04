#include"Client.h"
Client::Client(int id,std::string name, std::string password, double _balance):Person(id,name,password),balance(_balance){}
void Client::setBalance(double _balance) {
    balance = _balance;
}
double Client::getBalance() {
    return balance;
}
void Client::displayBalance() {
    cout<<"your balance is: "<<balance<<endl;
}
bool Client::withDraw(double amount) {
    if(BalanceServices::withDraw(getId(),amount,balance)) {
        cout << amount << " has been withdrawn successfully\n";
        return true;
    }
    else {
        return false;
    }
}
void Client::desposit(double amount) {
    BalanceServices::deposit(getId(),amount,balance);
    cout << amount << " has been added successfully to your balance\n";
}
bool Client::transferTo(double amount, Client &recipient) {
    if(BalanceServices::transferTo(getId(),recipient.getId(),amount,this->balance,recipient.balance)){
        return true;
    }
    else {
        return false;
    }
}
void Client::display() {
    cout<<"ID: "<<this->getId()
        <<endl<<"Name: "<<this->getName()
        <<endl<<"Password: "<<this->getPassword()
        <<endl<<"balance: "<<this->balance<<endl;
}

vector<Client> clients;