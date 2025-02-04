#include"EmployeeServices.h"
#include"FileManager.h"
#include"FilesHelper.h"
Client *EmployeeServices::searchClient(int id) {
    for (auto i = clients.begin(); i != clients.end() ; i++) {
        if (i->getId() == id){
            return &*i;
        }
    }
    return nullptr;
}

void EmployeeServices::editClient(int id, std::string name, std::string password, double balance) {
    vector<Client>::iterator x;
    for (x = clients.begin();x != clients.end();x++){
        if (id == x->getId()) {
            x->setName(name);
            x->setPassword(password);
            x->setBalance(balance);
            break;
        }
    }
    FileManager::removeAllClients();
    for (x = clients.begin(); x < clients.end(); x++) {
        saveClient(*x);
    }
}