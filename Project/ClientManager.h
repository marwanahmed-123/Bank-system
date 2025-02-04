#pragma once
#include"Person.h"
#include"Client.h"
using namespace std;
class ClientManager{
private:
    static void printClientMenu();
    static void updatePassword(Person*person);
public:
    static Client*login(int id,string password);
    static bool clientOptions(Client* client);
};