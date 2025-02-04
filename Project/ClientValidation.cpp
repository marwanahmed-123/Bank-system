#include"ClientValidation.h"

bool ClientValidation::validateBalance(double balance) {
    if (balance >= 1500 ){
        return true;
    }
    return false;
}