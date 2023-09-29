#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct  Client
{ 
    private:
        //define your private members here
        string client_name;
        string ssn;
        double bank_account;
        double balance;
};

Class Bank
{
    private:
    int num_client;
    Client *client_info;
    int index;

    public:
        //define your public members here
    void set_client_info(const string& client_name, const string& ssn, double bank_account, double balance);
    Client* get_client_info();
    double deposit(int account_number, double amount);
    string withdraw(int account_number, double amount);
    void saving_info(const string& file_name);
    void find_client(int account_number)
    Bank(const string& filename); //constructor
Bank(const Bank& other);
    ~Bank();
};

#endif
