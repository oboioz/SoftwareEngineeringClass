#include <iostream>

using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(int _accountNumber, string _accountHolderName, double _balance)
    {
        this->accountNumber = _accountNumber;
        this->accountHolderName = _accountHolderName;
        this->balance = _balance;
    }

    void deposit(double amount)
    {
        balance += amount;
    }

    void withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
        }
        else
        {
            cout << "Insufficient funds." << endl;
        }
    }

    double checkBalance()
    {
        return balance;
    }
};

int main()
{
    int accountNumber;
    string accountHolderName;
    double initialBalance;

    cout << "Enter account number: ";
    cin >> accountNumber;

    cout << "Enter account holder name: ";
    cin >> accountHolderName;

    cout << "Enter initial balance: ";
    cin >> initialBalance;

    BankAccount bankAccount(accountNumber, accountHolderName, initialBalance);

    int option = 0;

    while (option != 4)
    {
        cout << "Menu:" << endl;
        cout << "1. Deposit money" << endl;
        cout << "2. Withdraw money" << endl;
        cout << "3. Check balance" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> option;

        switch (option)
        {
        case 1:
        {
            double depositAmount;
            cout << "Enter the amount to deposit: ";
            cin >> depositAmount;

            bankAccount.deposit(depositAmount);

            cout << "Deposit successful." << endl;
            break;
        }

        case 2:
        {
            double withdrawAmount;
            cout << "Enter the amount to withdraw: ";
            cin >> withdrawAmount;

            bankAccount.withdraw(withdrawAmount);

            break;
        }

        case 3:
        {
            cout << "Your account balance is: " << bankAccount.checkBalance() << endl;
            break;
        }

        case 4:
        {
            cout << "Exiting..." << endl;
            break;
        }

        default:
        {
            cout << "Invalid choice." << endl;
        }
        }
    }

    return 0;
}
