#pragma once
#include"Client.h"
#include"Employee.h"
#include"Admin.h"
using namespace std;
class Screens{
    static void welcomeMessage();
    static void loginOptions();
    static int loginAs();
    static bool choiceValidityCheck(int c);
    static void logout();
    static int loginScreen();
    static Client* loginAsClient();
    static Employee* loginAsEmployee();
    static Admin* loginAsAdmin();
public:
    static void runApp();
};

