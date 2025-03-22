// 2.   Banking management system can be a good C++  project  for account creation, deposits, withdrawals, and balance inquiries. 

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Define a structure to represent an account
struct Account {
    int accountNumber;
    string accountHolderName;
    double balance;
};

// Function to create a new account
void createAccount(vector<Account>& accounts) {
    Account newAccount;
    cout << "Enter account number: ";
    cin >> newAccount.accountNumber;
    cout << "Enter account holder name: ";
    cin.ignore(); // Ignore the newline character left by cin
    getline(cin, newAccount.accountHolderName);
    cout << "Enter initial balance: ";
    cin >> newAccount.balance;
    
    accounts.push_back(newAccount);
    cout << "Account created successfully!" << endl;
}

// Function to display all accounts
void displayAccounts(const vector<Account>& accounts) {
    cout << "\nBank Accounts:" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << setw(15) << "Account No." << setw(25) << "Account Holder Name" << setw(15) << "Balance" << endl;
    cout << "--------------------------------------------------" << endl;
    for (const auto& account : accounts) {
        cout << setw(15) << account.accountNumber << setw(25) << account.accountHolderName << setw(15) << fixed << setprecision(2) << account.balance << endl;
    }
    cout << "--------------------------------------------------" << endl;
}

// Function to deposit money into an account
void deposit(vector<Account>& accounts, int accountNumber, double amount) {
    for (auto& account : accounts) {
        if (account.accountNumber == accountNumber) {
            account.balance += amount;
            cout << "Deposit successful. New balance: " << fixed << setprecision(2) << account.balance << endl;
            return;
        }
    }
    cout << "Account not found." << endl;
}

// Function to withdraw money from an account
void withdraw(vector<Account>& accounts, int accountNumber, double amount) {
    for (auto& account : accounts) {
        if (account.accountNumber == accountNumber) {
            if (account.balance >= amount) {
                account.balance -= amount;
                cout << "Withdrawal successful. New balance: " << fixed << setprecision(2) << account.balance << endl;
            } else {
                cout << "Insufficient funds." << endl;
            }
            return;
        }
    }
    cout << "Account not found." << endl;
}

int main() {
    vector<Account> accounts;
    int choice, accountNumber;
    double amount;

    do {
        cout << "\nBanking Management System\n";
        cout << "1. Create Account\n";
        cout << "2. Display Accounts\n";
        cout << "3. Deposit\n";
        cout << "4. Withdraw\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createAccount(accounts);
                break;
            case 2:
                displayAccounts(accounts);
                break;
            case 3:
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                deposit(accounts, accountNumber, amount);
                break;
            case 4:
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                withdraw(accounts, accountNumber, amount);
                break;
            case 5:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 5." << endl;
        }
    } while (choice != 5);

    return 0;
}