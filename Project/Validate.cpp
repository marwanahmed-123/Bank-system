#include"Validate.h"

bool Validate::validateName(std::string &name) {
    bool result = false;
    if (name.length() >= 5 && name.length() <= 20) {
        for (int i = 0; i < name.length(); i++) {
            if (name[i] >= 65 && name[i] <= 90 || name[i] >= 97 && name[i] <= 122 || name[i] == ' ') {
                result = true;
            }
            else {
                result = false;
                return result;
            }
        }
    }
    return result;
}
bool Validate::validatePassword(std::string &password) {
    bool result = false;
    if (password.length() >= 8 && password.length() <= 20) {
        for (int i = 0; i < password.length(); i++) {
            if (password[i] >= 33 && password[i] <= 127) {
                result = true;
            }
            else {
                result = false;
                return result;
            }
        }
    }
    return result;
}

bool Validate::validateMoney(double money) {
    if (money > 0){
        return true;
    }
    return false;
}