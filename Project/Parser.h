#pragma once
#include"Client.h"
#include<vector>
#include"Employee.h"
#include"Admin.h"
using namespace std;
class Parser{
public:
    static vector<string> split(const string& line);
    static Client parseToClient(const string& line);
    static Employee parseToEmployee(const string& line);
    static Admin parseToAdmin(const string& line);
};