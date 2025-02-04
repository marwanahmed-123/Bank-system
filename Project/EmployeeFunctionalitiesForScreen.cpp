#include"EmployeeFunctionalitiesForScreen.h"
#include"ClientValidation.h"
#include"FilesHelper.h"
void EmployeeFunctions::newClient(Employee *employee) {
    string name;
    string password;
    double balance;
    int nameTries=3;
    int passTries=3;
    int balanceTries=3;
    do{
        cout<<"enter client name: ";
        cin>>name;
        if (ClientValidation::validateName(name))
            break;
        cout<<"invalid name,try again\t"<<nameTries<<"left\n";
    } while (nameTries--);
    do{
        cout<<"enter client password: ";
        cin>>password;
        if (ClientValidation::validatePassword(password))
            break;
        cout<<"invalid password,try again\t"<<passTries<<"left\n";
    } while (passTries--);
    do{
        cout<<"enter client balance: ";
        cin>>balance;
        if (ClientValidation::validateBalance(balance))
            break;
        cout<<"invalid balance,try again\t"<<balanceTries<<"left\n";
    } while (balanceTries--);
    if (nameTries == 0 || passTries==0 || balanceTries==0) {
        cout << "too many fail attempts.\n";
        return;
    }
    Client x(getLast("clientLastId"),name,password,balance);
    employee->addClient(x);
    cout<<"Client added successfully!\n";
    getClients();
}

void EmployeeFunctions::listAllClients(Employee *employee) {
    for (auto i = clients.begin(); i != clients.end() ; ++i) {
        i->display();
    }
}

Client *EmployeeFunctions::searchForClient(Employee *employee) {
    cout<<"enter id of the client you want to search for: ";
    int tries = 3;
    do {
        int id;
        cin>>id;
        if (id < clients.size())
            return employee->searchClient(id);
    }while(tries--);
    return nullptr;
}

void EmployeeFunctions::editClientInfo(Employee *employee) {
    string newName;
    string newPassword;
    double newBalance;
    int id;
    int tries=3;
    cout<<"enter id of client you want to edit: ";
    do {
        cin>>id;
        if (id <= clients.size())
            break;
        cout<<"invalid id - remaining attempts:"<<tries<<endl;
    }while(tries--);
    if (tries==0){
        return;
    }
    int nameTries=3;
    int passTries=3;
    int balanceTries=3;
    do{
        cout<<"enter client name: ";
        cin>>newName;
        if (ClientValidation::validateName(newName))
            break;
    } while (nameTries--);
    do{
        cout<<"enter client password: ";
        cin>>newPassword;
        if (ClientValidation::validatePassword(newPassword))
            break;
    } while (passTries--);
    do{
        cout<<"enter client balance: ";
        cin>>newBalance;
        if (ClientValidation::validateBalance(newBalance))
            break;
    } while (balanceTries--);
    if (nameTries == 0 || passTries==0 || balanceTries==0) {
        cout << "too many fail attempts.\n";
        return;
    }
    employee->editClient(id,newName,newPassword,newBalance);
}