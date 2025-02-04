#pragma once
#include<iostream>
#include"Client.h"
#include"Employee.h"
using namespace std;
void saveLast(string fileName, int id);

int getLast(string fileName);

void saveClient(Client &c);

void saveEmployee(string fileName, Employee &e);

void getClients();

void getEmployees();

void getAdmins();

void clearFile(string fileName, string lastIdFile);