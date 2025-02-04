#include"Parser.h"
#include<vector>
#include"Employee.h"
#include"Admin.h"
vector<string> Parser::split(const std::string &line){
    vector<string> result;
    int flag=0;
    for (int i = 0; i < line.length(); i++) {
        if (line[i]==','){
            result.push_back(line.substr(flag,i-flag));
            flag=i+1;
        }
    }
    result.push_back(line.substr(flag,line.length()-flag));
    return result;
}

Client Parser::parseToClient(const std::string &line) {
    int id;
    string name,password;
    double balance;
    vector<string> result = split(line);
    id = stoi(result[0]);
    name = result[1];
    password = result [2];
    balance = stod(result[3]);
    Client resultf(id,name,password,balance);
    return resultf;
}

Employee Parser::parseToEmployee(const std::string &line) {
    int id;
    string name,password;
    double salary;
    vector<string> result = split(line);
    id = stoi(result[0]);
    name = result[1];
    password = result [2];
    salary = stod(result[3]);
    Employee resultf(id,name,password,salary);
    return resultf;
}

Admin Parser::parseToAdmin(const std::string &line) {
    int id;string name,password;double balance;
    int flag=0;
    int round = 1;
    vector<string> result = split(line);
    id = stoi(result[0]);
    name = result[1];
    password = result [2];
    balance = stod(result[3]);
    Admin resultf(id,name,password,balance);
    return resultf;
}