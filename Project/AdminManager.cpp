#include"AdminManager.h"
#include"EmployeeValidation.h"
#include"FilesHelper.h"
void AdminManager::printAdminOptions() {
    cout<< "1-add new client\n"
        << "2-search for client\n"
        << "3-list all clients\n"
        << "4-edit client info\n"
        << "5-display my info\n"
        << "6-add new employee\n"
        << "7-search for employee\n";
}
void AdminManager::newEmployee(Admin *admin) {
    string name;
    string password;
    double salary;
    int nameTries=3;
    int passTries=3;
    int salaryTries=3;
    do{
        cout<<"enter client name: ";
        cin>>name;
        if (EmployeeValidation::validateName(name))
            break;
        cout<<"invalid name,try again\t"<<nameTries<<"left\n";
    } while (nameTries--);
    do{
        cout<<"enter client password: ";
        cin>>password;
        if (EmployeeValidation::validatePassword(password))
            break;
        cout<<"invalid password,try again\t"<<passTries<<"left\n";
    } while (passTries--);
    do{
        cout<<"enter client balance: ";
        cin>>salary;
        if (EmployeeValidation::validateSalary(salary))
            break;
        cout<<"invalid balance,try again\t"<<salaryTries<<"left\n";
    } while (salaryTries--);
    if (nameTries == 0 || passTries==0 || salaryTries==0) {
        cout << "too many fail attempts.\n";
        return;
    }
    Employee x(getLast("employeeLastId.txt"),name,password,salary);
    admin->addEmployee(x);
    cout<<"Employee added successfully!\n";
    getEmployees();
}
Employee* AdminManager::searchForEmployee(Admin* admin){
    cout<<"search for:\n"
          "1-Employee"
          "2-Admin";
    char choice;
    cin>>choice;
    if(choice == '1') {
        cout<<"enter id of the employee you want to search for: ";
        int tries = 3;
        do {
            int id;
            cin >> id;
            if (id <= employees.size())
                return admin->searchEmployee(id);
        } while (tries--);
        return nullptr;
    }
    else if(choice=='2'){
        cout<<"enter id of the employee you want to search for: ";
        int tries = 3;
        do {
            int id;
            cin >> id;
            if (id <= admins.size())
                return admin->searchAdmin(id);
        } while (tries--);
        return nullptr;
    }
    else{
        cout<<"invalid choice!\n";
        return nullptr;
    }
}
Admin* AdminManager::login(int id, string password){
    vector<Admin>::iterator a;
    for (a = admins.begin(); a != admins.end(); ++a) {
        if (a->getId()==id && a->getPassword()==password) {
            return &*a;
        }
    }
    return nullptr;
}
bool AdminManager::adminOptions(Admin *admin){
    printAdminOptions();
    int choice;
    cin>>choice;
    switch (choice) {
        case 1:{
            newClient(admin);
        }return true;
        case 2:{
            Client* client = searchForClient(admin);
            if (client){
                client->display();
            }
        }return true;
        case 3:{
            listAllClients(admin);
        }return true;
        case 4:{
            editClientInfo(admin);
        }return true;
        case 5:{
            admin->display();
        }return true;
        case 6:{
            newEmployee(admin);
        }return true;
        case 7:{
            Employee* employee = searchForEmployee(admin);
            if (employee){
                employee->display();
            }
            else {
                cout << "Employee was not found!\n";
            }
        }return true;
        default:return false;
    }
}