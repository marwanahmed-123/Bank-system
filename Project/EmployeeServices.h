#pragma once
#include"Client.h"
using namespace std;
class EmployeeServices{
public:
    static Client* searchClient(int id);
    static void editClient(int id, string name, string password, double balance);
};