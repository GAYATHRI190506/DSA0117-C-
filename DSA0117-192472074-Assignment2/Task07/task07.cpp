#include <iostream>
using namespace std;

class Account
{
private:
    int balance;
    static int accountCount;

public:
    Account(int b)
    {
        balance = b;
        accountCount++;
    }

    void deposit(int amount)
    {
        balance += amount;
    }

    int getBalance() const
    {
        return balance;
    }

    static int getAccountCount()
    {
        return accountCount;
    }

    friend void transfer(Account& from, Account& to, int amount);
};

int Account::accountCount = 0;

void transfer(Account& from, Account& to, int amount)
{
    if (amount > 0 && amount <= from.balance)
    {
        from.balance -= amount;
        to.balance += amount;
    }
}

int main()
{
    Account a1(5000);
    Account a2(3000);

    cout << "Initial Balance of Account 1: "
         << a1.getBalance() << '\n';

    cout << "Initial Balance of Account 2: "
         << a2.getBalance() << '\n';

    a1.deposit(1000);

    cout << "After Deposit - Account 1: "
         << a1.getBalance() << '\n';

    transfer(a1, a2, 2000);

    cout << "After Transfer - Account 1: "
         << a1.getBalance() << '\n';

    cout << "After Transfer - Account 2: "
         << a2.getBalance() << '\n';

    cout << "Total Accounts: "
         << Account::getAccountCount() << '\n';

    return 0;
}