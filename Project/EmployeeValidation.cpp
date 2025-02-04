#include"EmployeeValidation.h"

bool EmployeeValidation::validateSalary(double salary) {
    if (salary >= 5000 ){
        return true;
    }
    return false;
}