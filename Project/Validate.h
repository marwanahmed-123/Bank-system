#pragma once
#include<iostream>
using namespace std;
class Validate{
public:
    static bool validateName(string& name);
    static bool validatePassword(string& password);
    static bool validateMoney(double money);
};