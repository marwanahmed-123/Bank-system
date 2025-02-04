#pragma once
#include"Validate.h"
class EmployeeValidation:public Validate{
public:
    static bool validateSalary(double salary);
};