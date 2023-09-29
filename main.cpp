#include "client.h" // Include your client class definition
#include <iostream>
#include <string>

using namespace std;

int main() {
   
    Bank bank("client_data.txt");

    // Set client information for the first client (assuming there is at least one client in your file)
    bank.set_client_info("CarlosMcpherson", "123-45-6789", 12345, 34567);

    // Deposit money into account 1001
    double newBalance = bank.deposit(12345, 10000.0);
    cout << "New balance for account 1001: $" << newBalance << endl;

    // Withdraw money from account 1001
    string withdrawResult = bank.withdraw(12345, 2000.0);
    cout << withdrawResult << endl;

    // Find a client by account number
    bank.find_client(12345);

    // Save client information to a file
    bank.saving_info("updated_client_data.txt");

    return 0;
}
