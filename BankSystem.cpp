#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Account {
    string user_name;
    string cnic;
    unsigned long long acc_no;
    int pin;
    string DOB;
    int balance;
    bool is_deactivated;
};

vector<Account> accounts;
int current_user_index = -1;

void create_account()
{
    Account new_account;
    int PIN, con_pin;
    srand(time(0));
    cout << "To create an account please enter your information" << endl;
    cout << "Enter your Name: ";
    cin.ignore();
    getline(cin, new_account.user_name);
    cout << "Enter your National Identity Card No: ";
    getline(cin, new_account.cnic);
    cout << "Enter your Date of Birth (DD/MM/YYYY): ";
    getline(cin, new_account.DOB);
    new_account.acc_no = 10000000000 + rand() % 900000000000;
    cout << "Your Account Number is: " << new_account.acc_no << endl;
    cout << "Please set a PIN for your Account: ";
    cin >> PIN;
    cout << "Please re-confirm your PIN: ";
    cin >> con_pin;
    while (PIN != con_pin) 
    {
        cout << "Your PIN did not match. Please re-enter your PIN for confirmation: ";
        cin >> con_pin;
    }
    new_account.pin = PIN;
    new_account.balance = 0;
    new_account.is_deactivated = false;
    accounts.push_back(new_account);
    cout << "Your account has been created!" << endl;
}

void deposit_Money()
{
    int amount;
    cout << "Enter the amount you want to deposit: Rs. ";
    cin >> amount;
    accounts[current_user_index].balance += amount;
    cout << "Your current balance is: Rs." << accounts[current_user_index].balance << endl;
}

void Withdraw_Money()
{
    int amount;
    cout << "Enter the amount you want to withdraw: Rs. ";
    cin >> amount;
    if (amount <= accounts[current_user_index].balance) 
    {
        accounts[current_user_index].balance -= amount;
        cout << "Your withdrawal was successful. New balance is: Rs." << accounts[current_user_index].balance << endl;
    } 
    else 
    {
        cout << "Insufficient balance to complete the withdrawal.\n";
    }
}

void transfer_money()
{
    int n;
    cout << "1. Inter Bank" << endl;
    cout << "2. Other Bank" << endl;
    cout << "3. Cancel" << endl;
    cin >> n;
    switch (n) 
    {
        case 1: 
        {
            string recipient_CNIC;
            int amount;
            cout << "Enter the recipient's CNIC: ";
            cin >> recipient_CNIC;
            bool recipient_found = false;
            for (int j = 0; j < accounts.size(); j++) 
            {
                if (accounts[j].cnic == recipient_CNIC) 
                {
                    recipient_found = true;
                    cout << "Enter the amount to transfer: Rs. ";
                    cin >> amount;
                    if (amount <= accounts[current_user_index].balance)
                    {
                        accounts[current_user_index].balance -= amount;
                        accounts[j].balance += amount;
                        cout << "Transfer successful! Rs." << amount << " has been transferred to " << accounts[j].user_name << "." << endl;
                    } 
                    else 
                    {
                        cout << "Insufficient balance to complete the transfer." << endl;
                    }
                    break;
                }
            }
            if (!recipient_found) 
            {
                cout << "Recipient account not found." << endl;
            }
            break;
        }
        case 2: 
        {
            string recipient_account, recipient_bank;
            int amount;
            cout << "Enter the recipient's account number: ";
            cin >> recipient_account;
            cout << "Enter the recipient's bank name: ";
            cin >> recipient_bank;
            cout << "Enter the amount to transfer: Rs. ";
            cin >> amount;
            if (amount <= accounts[current_user_index].balance) 
            {
                accounts[current_user_index].balance -= amount;
                cout << "Transfer successful! Rs." << amount << " has been transferred to account number " << recipient_account << " at " << recipient_bank << "." << endl;
            } 
            else 
            {
                cout << "Insufficient balance to complete the transfer." << endl;
            }
            break;
        }
        case 3:
            cout << "Transfer canceled." << endl;
            break;
        default:
            cout << "Invalid option selected. Please try again." << endl;
            break;
    }
}

void check_balance()
{
    cout << "Your current balance is: Rs." << accounts[current_user_index].balance << endl;
}

void billpay()
{
    int amount;
    long int billno;
    cout << "Enter your bill number to pay: ";
    cin >> billno;
    cout << "Enter the amount of the bill: Rs. ";
    cin >> amount;
    if (amount <= accounts[current_user_index].balance) 
    {
        accounts[current_user_index].balance -= amount;
        cout << "Your bill has been paid. Bill Number: " << billno << endl;
    } 
    else 
    {
        cout << "Insufficient balance to pay the bill.\n";
    }
}

void deactivate_account()
{
    accounts[current_user_index].is_deactivated = true;
    cout << "Your account is now deactivated.\n";
}

void show_all_accounts()
{
    for (int i = 0; i < accounts.size(); i++) 
    {
        cout << "Account " << i + 1 << ":" << endl;
        cout << "Name: " << accounts[i].user_name << endl;
        cout << "CNIC: " << accounts[i].cnic << endl;
        cout << "Account Number: " << accounts[i].acc_no << endl;
        cout << "Date of Birth: " << accounts[i].DOB << endl;
        cout << "Balance: Rs." << accounts[i].balance << endl;
        cout << "----------------------------" << endl;
    }
}

void search_account()
{
    bool found = false;
    string CNIC;
    cout << "Enter CNIC to search Account: ";
    cin >> CNIC;
    for (int i = 0; i < accounts.size(); i++) 
    {
        if (accounts[i].cnic == CNIC) 
        {
            found = true;
            cout << "Name: " << accounts[i].user_name << endl;
            cout << "PIN: " << accounts[i].pin << endl;
            cout << "Date of Birth: " << accounts[i].DOB << endl;
            cout << "Balance: Rs." << accounts[i].balance << endl;
        }
    }
    if (!found) 
    {
        cout << "Account not found.\n";
    }
}

void delete_account()
{
    string CNIC, username;
    int PIN;
    cout << "Enter your CNIC: ";
    cin >> CNIC;
    bool cnic_found = false;
    for (int i = 0; i < accounts.size(); i++) 
    {
        if (accounts[i].cnic == CNIC) 
        {
            cnic_found = true;
            cout << "Enter your PIN: ";
            cin >> PIN;
            if (PIN == accounts[i].pin) 
            {
                cout << "Enter your username: ";
                cin >> username;
                cout << "Your account has been deleted.\n";
                accounts.erase(accounts.begin() + i);
                break;
            } 
            else 
            {
                cout << "Incorrect PIN. Account deletion failed.\n";
            }
        }
    }
    if (!cnic_found) 
    {
        cout << "Account not found.\n";
    }
}

void modify_balance()
{
    int new_balance;
    cout << "Enter your new balance: ";
    cin >> new_balance;
    accounts[current_user_index].balance = new_balance;
    cout << "Your new balance is Rs." << accounts[current_user_index].balance << endl;
}

void modify_pin()
{
    int new_pin;
    cout << "Enter your new PIN: ";
    cin >> new_pin;
    accounts[current_user_index].pin = new_pin;
    cout << "Your new PIN has been set to: " << accounts[current_user_index].pin << endl;
}

void user_side()
{
    string CNIC;
    int PIN;
    cout << "Enter your CNIC: ";
    cin >> CNIC;

    for (int i = 0; i < accounts.size(); i++) 
    {
        if (accounts[i].cnic == CNIC) 
        {
            current_user_index = i;
            cout << "Enter your PIN: ";
            cin >> PIN;

            if (PIN == accounts[i].pin) 
            {
                int n;
                do 
                {
                    cout << "Select a service:" << endl;
                    cout << "1. Deposit Money" << endl;
                    cout << "2. Withdraw Money" << endl;
                    cout << "3. Balance Inquiry" << endl;
                    cout << "4. Deactivate Account" << endl;
                    cout << "5. Bill Payment" << endl;
                    cout << "6. Transfer Money" << endl;
                    cout << "0. Exit" << endl;
                    cin >> n;
                    switch (n) 
                    {
                    case 1:
                        deposit_Money();
                        break;
                    case 2:
                        Withdraw_Money();
                        break;
                    case 3:
                        check_balance();
                        break;
                    case 4:
                        deactivate_account();
                        break;
                    case 5:
                        billpay();
                        break;
                    case 6:
                        transfer_money();
                        break;
                    case 0:
                        break;
                    }
                } while (n != 0);
            } 
            else 
            {
                cout << "Incorrect PIN.\n";
            }
            break;
        }
    }
}

void admin_side()
{
    int n;
    do 
    {
        cout << "Select a service:" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Show all Accounts" << endl;
        cout << "3. Search Account" << endl;
        cout << "4. Modify Balance" << endl;
        cout << "5. Change PIN" << endl;
        cout << "6. Delete Account" << endl;
        cout << "0. Exit" << endl;
        cin >> n;

        switch (n) 
        {
        case 1:
            create_account();
            break;
        case 2:
            show_all_accounts();
            break;
        case 3:
            search_account();
            break;
        case 4:
            modify_balance();
            break;
        case 5:
            modify_pin();
            break;
        case 6:
            delete_account();
            break;
        }
    } while (n != 0);
}

int main()
{
    int n;
    cout << "Please choose your access:" << endl;
    cout << "1. Admin Access" << endl;
    cout << "2. User Login" << endl;
    cout << "0. Cancel" << endl;
    cin >> n;

    switch (n) 
    {
    case 1:
        admin_side();
        break;
    case 2:
        user_side();
        break;
    case 0:
        break;
    }

    return 0;
}
