#pragma once
#include"Validate.h"
class ClientValidation:public Validate{
public:
    static bool validateBalance(double balance);
};