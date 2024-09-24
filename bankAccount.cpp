#include <iostream>
#include <iomanip>
using namespace std;

class account
{
    string name;
    string accountNumber;
    double balance;

public:
    account();
    account(string accountName, string account_Number, double accountBalance);
    void getInfo(void) const;
    double getBalance(void) const;
    void deposit(double amount);
    void withdraw(double amount);
};

account::account(string accountName, string account_Number, double accountBalance) : name(accountName), accountNumber(account_Number), balance(accountBalance) {};

void account::getInfo() const
{
    cout << "Name : " << name << endl;
    cout << "Account Number : " << accountNumber << endl;
    cout << "Balance : " << balance << endl;
}

double account::getBalance() const
{
    return balance;
}

void account::deposit(double amount)
{
    if (amount <= 0)
    {
        cout << "Invalid Amount\a\n";
    }
    else
        balance += amount;
}

void account::withdraw(double amount)
{
    if (amount <= 0)
    {
        cout << "Invalid Amount\a\n";
    }
    else if (amount > balance)
    {
        cout << "Can't withdraw money, your balance is " << balance << endl;
    }
    else
    {
        balance -= amount;
        cout << "you withdraw " << amount << "taka\nNow your balance is " << balance << endl;
    }
}

int menu()
{
    cout << "Type Your Choice:\n\n";
    cout << "1. Account Information\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Balance\n";
    cout << "0. exit\n\n";
    int choice;
    cin >> choice;
    return choice;
}

void action(int choice, account &person)
{
    switch (choice)
    {
    case 1:
        person.getInfo();
        break;
    case 2:
        cout << "Type your deposit amount: ";
        double depositAmount;
        cin >> depositAmount;
        person.deposit(depositAmount);
        break;
    case 3:
        cout << "Type your withdraw amount: ";
        double WithdrawAmount;
        cin >> WithdrawAmount;
        person.withdraw(WithdrawAmount);
        break;
    case 4:
        cout << "Your balance:" << fixed << setprecision(2) << person.getBalance() << endl;
        break;
    case 0:
        cout << "Thank you";
        break;
    default:
        cout << "Invalid Choice\a\n";
    }
}

int main()
{

    account person1("Niloy Hasan Nahid", "2233081350", 10000);
    int choice;
    do
    {
        choice = menu();
        action(choice, person1);
    } while (choice);
    return 0;
}