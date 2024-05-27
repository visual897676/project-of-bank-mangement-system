#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void menu();
void new_account();
void account_details();
void account_withdraw();
void account_deposit();


ifstream rfile;
ofstream wfile;

struct bank 
{
    string holder_name;
    int account_number;
    string account_type;
    double balance;
};

const int MAX_ACCOUNTS = 100;
bank accounts[MAX_ACCOUNTS];
int totalAccounts = 0;

bool login() 
{
    string useradmin, password;
    const string UserAdmin = "admin";
    const string Password = "12345";

    cout << "Under Construction\n";
    cout << "Enter admin: ";
    cin >> useradmin;
    cout << "Enter Password: ";
    cin >> password;

    if (UserAdmin == useradmin && Password == password) {
        cout << "Access granted \nWelcome to the admin console of the BANK MANGEMENT SYSTEM\n";
        return true;
    }
    else {
        cout << "Invalid Credentials, try later";
        return false;
    }
}

int main() 
{
    if (!login()) {
        return 1;
    }

    int choice;
    do {
        menu();
        cin >> choice;

        switch (choice) {
            case 1:
                new_account();
                break;
            case 2:
                account_details();
                break;
            case 3:
                account_withdraw();
                break;
            case 4:
                account_deposit();
                break;
            case 5:
                cout << "\nExiting..." << endl;
                break;
            default:
                cout << "\nInvalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

void menu()
{
    cout << "\n1. New Account";
    cout << "\n2. Account Details";
    cout << "\n3. Withdraw Amount";
    cout << "\n4. Deposit Amount";
    cout << "\n5. Exit";
    cout << "\n\nEnter your choice: ";
}

void new_account() 
{
    system("cls");
    int account_number;
    string holder_name;
    char account_type;
    double balance;
    
    cout << "\n\nEnter Account Number: ";
    cin >> account_number;
    cout << "\nEnter Account Holder's Name: ";
    cin.ignore();
    getline(cin, holder_name);
    cout << "\nEnter type of Account ('C' for Current/'S' for Saving): ";
    cin >> account_type;
    cout << "\nEnter initial balance: ";
    cin >> balance;

    bank newAcc;
    newAcc.account_number = account_number;
    newAcc.holder_name = holder_name;
    newAcc.account_type = account_type;
    newAcc.balance = balance;

    accounts[totalAccounts++] = newAcc;

    cout << "\n\tAccount Created Successfully." << endl;
}

void account_details() 
{
    system("cls");
    int values = totalAccounts;

    string accNo;
    cout << "\n\nEnter account number: ";
    cin >> accNo;
    for (int i = 0; i < values; i++) {
        if (accNo == to_string(accounts[i].account_number)) {
            cout << "\nAccount Number: " << accounts[i].account_number;
            cout << "\nAccount Holder's Name: " << accounts[i].holder_name;
            cout << "\nAccount Type: " << accounts[i].account_type;
            cout << "\nBalance: " << accounts[i].balance << " RS" << endl;
            return;
        }
    }
    cout << "\n\tAccount not found." << endl;
}

void account_withdraw() 
{
    system("cls");
    int values = totalAccounts;

    string accNo;
    cout << "\n\nEnter account number: ";
    cin >> accNo;
    for (int i = 0; i < values; i++) {
        if (accNo == to_string(accounts[i].account_number)) {
            double amount;
            cout << "\n\tEnter amount to withdraw: ";
            cin >> amount;
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                cout << "\nWithdrawal successful." << endl;
                cout << "\nRemaining Balance: " << accounts[i].balance << " RS" << endl;
            } else {
                cout << "\nInsufficient balance." << endl;
            }
            return;
        }
    }
    cout << "\nAccount not found." << endl;
}

void account_deposit() 
{
    system("cls");
    int values = totalAccounts;

    string accNo;
    cout << "\n\n\tEnter account number: ";
    cin >> accNo;
    for (int i = 0; i < values; i++) {
        if (accNo == to_string(accounts[i].account_number)) {
            double amount;
            cout << "\n\tEnter amount to deposit: ";
            cin >> amount;
            if (amount > 0) {
                accounts[i].balance += amount;
                cout << "\nDeposit successful." << endl;
                cout << "\nUpdated Balance: " << accounts[i].balance << " RS" << endl;
            } else {
                cout << "\n\tInvalid amount." << endl;
            }
            return;
        }
    }
    cout << "\nAccount not found." << endl;
}
