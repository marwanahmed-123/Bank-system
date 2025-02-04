#include"Screens.h"
#include"ClientManager.h"
#include"EmployeeManager.h"
#include"AdminManager.h"
#include"FilesHelper.h"
#include <unistd.h>
void Screens::welcomeMessage() {
    cout<<"Welcome to our bank system\n";
}

void Screens::loginOptions() {
    cout<<"login as:\n1-Client\n2-Employee\n3-Admin\n";
}

int Screens::loginAs() {
    int choice;
    cin>>choice;
    return choice;
}

bool Screens::choiceValidityCheck(int c) {
    if (c == 0){
        cout<<"invalid option\n";
        return false;
    }
    else if (c >= 1 && c <= 3){
        return true;
    }
    return false;
}

void Screens::logout() {
    system("CLS");
}

int Screens::loginScreen() {
    int tries=3;
    do {
        int loggedIn;
        loginOptions();
        loggedIn = loginAs();
        if (choiceValidityCheck(loggedIn))
            return loggedIn;
        cout<<tries<<" attempts left\n";
    }while(tries--);
    return -1;
}

Client *Screens::loginAsClient() {
    int id;
    string password;
    int loginAttempts=3;
    do {
        cout<<"enter id:";
        cin>>id;
        cout<<"enter password:";
        cin>>password;
        Client*client = ClientManager::login(id,password);
        if (client){
            return client;
        }
        cout<<loginAttempts<<" attempts left\n";
    }while(loginAttempts--);
    return nullptr;
}

Employee *Screens::loginAsEmployee() {
    int id;
    string password;
    int loginAttempts=3;
    do {
        cout<<"enter id:";
        cin>>id;
        cout<<"enter password:";
        cin>>password;
        Employee* employee = EmployeeManager::login(id,password);
        if (employee){
            return employee;
        }
        cout<<loginAttempts<<" attempts left\n";
    }while(loginAttempts--);
    return nullptr;
}

Admin *Screens::loginAsAdmin() {
    int id;
    string password;
    int loginAttempts=3;
    do {
        cout<<"enter id:";
        cin>>id;
        cout<<"enter password:";
        cin>>password;
        if (AdminManager::login(id,password)){
            return AdminManager::login(id,password);
        }
        cout<<loginAttempts<<" attempts left\n";
    }while(loginAttempts--);
    return nullptr;
}

void Screens::runApp() {
    getClients();
    getEmployees();
    getAdmins();
    saveLast("clientLastId.txt",clients.size());
    saveLast("employeeLastId.txt",employees.size());
    saveLast("adminLastId.txt",admins.size());
    while (true){
        int x = loginScreen();
        if (x == 1) {
            Client* client = loginAsClient();
            bool choice=true;
            while (ClientManager::clientOptions(client)&&choice){
            cout<<"1-continue\n"
                <<"0-logout\n";
                cin>>choice;
                if (choice == 0){
                    logout();
                    break;
                }
            }
        }
        else if (x == 2) {
            Employee* employee = loginAsEmployee();
            bool choice=true;
            while (EmployeeManager::employeeOptions(employee)&&choice){
                cout<<"1-continue\n"
                    <<"0-logout\n";
                cin>>choice;
                if (choice == 0){
                    logout();
                    break;
                }
            }
        }
        else if (x == 3) {
            bool c;
            Admin* admin = loginAsAdmin();
            int attempts=3;
            bool choice=true;
            while (AdminManager::adminOptions(admin)&&choice){
                cout<<"1-continue\n"
                    <<"0-logout\n";
                cin>>choice;
            }
        }
        else {
            cout << "failed to log in,you can try again in 10 seconds\n";
            sleep(10);
        }
    }
}