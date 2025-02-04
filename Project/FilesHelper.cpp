#include"FilesHelper.h"
#include"Parser.h"
#include"Person.h"
#include<fstream>
void saveLast(string fileName, int id){
    ofstream file;
    file.open(fileName,ios::trunc);
    if(!file){
        cout<<"error opening the file\n";
        return;
    }
    file << id;
    file.close();
}
int getLast(string fileName) {
    ifstream file;
    int last_id=0;
    string result;
    file.open(fileName);
    if (!file.is_open()) {
        cout << "error opening the file\n";
        return -1;
    }
    else{
        if (getline(file,result)){
            last_id= stoi(result);
        }
    }
    file.close();
    return last_id;
}
void saveClient(Client &c) {
    ofstream file("client.txt", ios::app);
    if (!file.is_open()){
        cout<<"error opening file";
        return;
    }
    else{
        int last_id= getLast("clientLastId.txt");
        last_id++;
        c.setId(last_id);
        saveLast("clientLastId.txt",last_id);
        file<< c.getId() << ","
            << c.getName() << ","
            << c.getPassword() << ","
            << c.getBalance()<<"\n";
        file.close();
    }
}
void saveEmployee(string fileName, Employee &e) {
    ofstream file(fileName, ios::app);
    if (!file.is_open()){
        cout<<"error opening employee folder";
    }
    else{
        if (fileName=="employee.txt"){
            int last_id= getLast("employeeLastId.txt");
            last_id++;
            e.setId(last_id);
            saveLast("adminLastId.txt",last_id);
            file<< e.getId() << ","
                << e.getName() << ","
                << e.getPassword() << ","
                << e.getSalary()<<"\n";
            file.close();
        }
        else if (fileName=="admin.txt"){
            int last_id= getLast("adminLastId.txt");
            last_id++;
            e.setId(last_id);
            saveLast("adminLastId.txt",last_id);
            file<< e.getId() << ","
                << e.getName() << ","
                << e.getPassword() << ","
                << e.getSalary()<<"\n";
            file.close();
        }
    }
    file.close();
}
void getClients() {
    ifstream file("client.txt");
    string line;
    if (!file) {
        cout << "error opening the file!\n";
    }
    else{
        while (getline(file, line)) {
            bool flag = true;
            for (auto i:clients) {
                if (i.getId()==Parser::parseToClient(line).getId()){
                    flag = false;
                    break;
                }
            }
            if (flag){
                clients.push_back(Parser::parseToClient(line));
            }
        }
    }
    file.close();
}
void getEmployees() {
    ifstream file("employee.txt");
    string line;
    if (!file) {
        cout << "error opening the file!\n";
    }
    else{
        while (getline(file, line)) {
            bool flag = true;
            for (auto i:employees) {
                if (i.getId()==Parser::parseToEmployee(line).getId()){
                    flag = false;
                    break;
                }
            }
            if (flag){
                employees.push_back(Parser::parseToEmployee(line));
            }
        }
    }
    file.close();
}
void getAdmins() {
    ifstream file("admin.txt");
    string line;
    if (!file) {
        cout << "error opening the file!\n";
    }
    else{
        while (getline(file, line)) {
            bool flag = true;
            for (auto i:admins) {
                if (i.getId()==Parser::parseToAdmin(line).getId()){
                    flag = false;
                    break;
                }
            }
            if (flag){
                admins.push_back(Parser::parseToAdmin(line));
            }
        }
    }
    file.close();
}
void clearFile(string fileName, string lastIdFile) {
    ofstream file1(fileName, ios::trunc);
    if (!file1.is_open()){
        cout<<"error opening "<<fileName<<"\n";
        return;
    }
    ofstream file2(lastIdFile, ios::trunc);
    saveLast(lastIdFile,0);
    if (!file2.is_open()){
        cout<<"error opening "<<lastIdFile<<"\n";
        return;
    }
    file1.close();
    file2.close();
}