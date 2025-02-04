#include"BalanceServices.h"
#include"Client.h"
#include"FileManager.h"
#include"FilesHelper.h"
bool BalanceServices::withDraw(int id,double amount, double &balance) {
    if (abs(amount) > balance) {
        return false;
    }
    balance-=abs(amount);
    vector<Client>::iterator x;
    for (x = clients.begin();x != clients.end();x++){
        if (id == x->getId()) {
            x->setBalance(balance);
            break;
        }
    }
    FileManager::removeAllClients();
    for (x = clients.begin(); x < clients.end(); x++) {
        saveClient(*x);
    }
    return true;
}
void BalanceServices::deposit(int id,double amount, double &balance) {
    balance+=amount;
    vector<Client>::iterator x;
    for (x = clients.begin();x != clients.end();x++){
        if (id == x->getId()) {
            x->setBalance(balance);
            break;
        }
    }
    FileManager::removeAllClients();
    for (x = clients.begin(); x < clients.end(); x++) {
        saveClient(*x);
    }
}
bool BalanceServices::transferTo(int senderId,int recipientId,double amount, double &senderBalance, double &recipientBalance) {
    if(senderBalance >= amount) {
        recipientBalance+=amount;
        bool flag1=false,flag2=false;
        senderBalance-=amount;
        vector<Client>::iterator x;
        for (x = clients.begin();x != clients.end();x++){
            if (senderId == x->getId()) {
                x->setBalance(senderBalance);
                flag1=true;
            }
            else if(recipientId==x->getId()){
                x->setBalance(recipientBalance);
                flag2=true;
            }
            if (flag1&&flag2) {
                break;
            }
        }
        FileManager::removeAllClients();
        for (x = clients.begin(); x < clients.end(); x++) {
            saveClient(*x);
        }
        return true;
    }
    return false;
}