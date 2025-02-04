#include"EmployeeManager.h"

void EmployeeManager::printEmployeeMenu() {
    cout<< "1-add new client\n"
        << "2-search for client\n"
        << "3-list all clients\n"
        << "4-edit client info\n"
        << "5-display my info\n";
}

Employee *EmployeeManager::login(int id, std::string password) {
    for (auto i = employees.begin(); i != employees.end(); ++i) {
        if (i->getId()==id && i->getPassword()==password) {
            return &*i;
        }
    }
    return nullptr;
}

bool EmployeeManager::employeeOptions(Employee *employee) {
    printEmployeeMenu();
    int choice;
    cin>>choice;
    switch (choice) {
        case 1:{
            newClient(employee);
        }return true;
        case 2:{
            Client* client = searchForClient(employee);
            if (client){
                client->display();
            }
            else {
                cout << "Client was not found!\n";
            }
        }return true;
        case 3:{
            listAllClients(employee);
        }return true;
        case 4:{
            editClientInfo(employee);
        }return true;
        case 5:{
            employee->display();
        }return true;
        default:return false;
    }
}