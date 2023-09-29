#include "client.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Bank::Bank(const string& filename) {
   ifstream file(filename);
    index = 0;
    if (!file.is_open()) {
        cout << "Error: Unable to open file " << filename << endl;
        // You might want to handle this error differently (e.g., throw an exception).
        return;
    }

    // Read the number of clients from the file
    file >> num_client;

    // Allocate memory for the client_info array
    client_info = new Client[num_client];

    // Read client information from the file
    for (int i = 0; i < num_client; i++) {
        file >> client_info[i].client_name;
        file >> client_info[i].ssn;
        file >> client_info[i].bank_account;
        file >> client_info[i].balance;
    }

    file.close();
}


Bank::~Bank() {
    delete[] client_info;
}


Bank::Bank(const Bank& other) {
    num_client = other.num_client;
    client_info = new Client[num_client];

    for (int i = 0; i < num_client; i++) {
        client_info[i] = other.client_info[i];
    }
}

void Bank::set_client_info(const string& client_name, const string& ssn, double bank_account, double balance) {
    
  if (index >= 0 && index < num_client) {
        client_info[index].client_name = client_name;
        client_info[index].ssn = ssn;
        client_info[index].bank_account = bank_account;
        client_info[index].balance = balance;
    } else {
        cout << "Error: Invalid index. Index should be between 0 and " << num_client - 1 << endl;
    }
}


Client* Bank::get_client_info() {
    return client_info;
}


double Bank::deposit(int account_number, double amount) {
    for (int i = 0; i < num_client; i++) {
        if (client_info[i].bank_account == account_number) {
            client_info[i].balance += amount;
            return client_info[i].balance;
        }
    }
    return -1.0;
}

string Bank::withdraw(int account_number, double amount) {
    for (int i = 0; i < num_client; i++) {
        if (client_info[i].bank_account == account_number) {
            if (client_info[i].balance >= amount) {
                client_info[i].balance -= amount;
                return "Withdraw successful. New balance: " + to_string(client_info[i].balance);
            } else {
                return "Insufficient balance for withdrawal.";
            }
        }
    }
    return "Account not found.";
}

void Bank::saving_info(const string& filename) {
    ofstream file(filename);

    if (!file.is_open()) {
        cout << "Error: Unable to save to file " << filename << endl;
        return;
    }

    file << num_client << endl;

    for (int i = 0; i < num_client; i++) {
        file << client_info[i].client_name << " ";
        file << client_info[i].ssn << " ";
        file << client_info[i].bank_account << " ";
        file << client_info[i].balance << endl;
    }

    file.close();
}

void Bank::find_client(int account_number) {
    bool found = false;

    for (int i = 0; i < num_client; i++) {
        if (client_info[i].bank_account == account_number) {
            cout << "Account number: " << account_number << endl;
            cout << "Name: " << client_info[i].client_name << endl;
            cout << "Balance: " << client_info[i].balance << endl;
            cout << "SSN: " << client_info[i].ssn << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Client is not in the list." << endl;
    }
}

