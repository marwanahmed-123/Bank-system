#pragma once
#include<iostream>
using namespace std;
class BalanceServices{
public:
    static bool withDraw(int id,double amount , double& balance);
    static void deposit(int id,double amount, double&balance);
    static bool transferTo(int senderId,int recipientId,double amount,double& senderBalance,double& recipientBalance);
};