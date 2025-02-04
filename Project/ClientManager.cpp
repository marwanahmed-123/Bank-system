#include"ClientManager.h"
#include"ClientValidation.h"
void ClientManager::printClientMenu() {
    cout<<"1-withdraw\n"
        <<"2-deposit\n"
        <<"3-check balance\n"
        <<"4-transfer money to another account\n";
}

void ClientManager::updatePassword(Person *person) {
    cout<<"please enter your new password: ";
    string newPass;
    cin>>newPass;
    if(Validate::validatePassword(newPass)){
        person->setPassword(newPass);return;
    }
    cout<<"invalid password\n";
}

Client *ClientManager::login(int id, std::string password) {
    for (auto & client : clients) {
        if (client.getId()==id && client.getPassword() == password){
            return &client;
        }
    }
    return nullptr;
}

bool ClientManager::clientOptions(Client *client) {
    printClientMenu();
    int choice;
    cin>>choice;
    int flag = 3;
    switch (choice) {
        case 1:{
            double amount;
            while (flag) {
                cout<<"enter amount to withdraw:";cin>>amount;
                if (!client->withDraw(amount)){
                    cout<<"invalid amount!\n";
                    cout<<"you have "<<flag<<" more tries\n";
                }
                else {
                    return true;
                }
                flag--;
            }
            cout<<"withdraw refused!\n";
        }return true;
        case 2:{
            double amount;
            while (flag) {
                cout<<"enter amount to deposit:";cin>>amount;
                if (!ClientValidation::validateMoney(amount)){
                    cout<<"invalid amount!\n";
                    cout<<"you have "<<flag<<" more tries\n";
                }
                else {
                    client->desposit(amount);
                    return true;
                }
                flag--;
            }
            cout<<"withdraw refused!\n";
        }return true;
        case 3:{
            cout<<"your balance is:"<<client->getBalance()<<endl;
        }return true;
        case 4:{
            double amount;
            int recipientId;
            bool confirmation=0;
            int tries = 3;
            do{
                cout<<"enter id for the recipient:";cin>>recipientId;
                cout<<"enter amount you want to transfer:";cin>>amount;
                if (recipientId==client->getId()){
                    cout<<"something went wrong.\n";
                    break;
                }
                cout<<recipientId<<" confirm this is the recipient, enter 1 -> yes or 0 -> no\n";
                cin>>confirmation;
                if (confirmation){
                    for (auto i = clients.begin(); i != clients.end(); ++i) {
                        if (recipientId==i->getId()){
                            if (client->transferTo(amount,*i)){
                                cout<<amount<<" has been transferred successfully to "<<i->getName()<<endl;
                                return true;
                            }
                            else{
                                cout<<"insufficient balance\n";
                                return true;
                            }
                        }
                    }
                }
                cout<<"something went wrong,try again.\n";
                tries--;
            }while(tries);
        }return true;
        default:return false;
    }
}