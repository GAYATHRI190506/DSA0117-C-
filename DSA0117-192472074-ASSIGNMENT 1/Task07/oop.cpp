#include <iostream>

using namespace std;

class SmartCard
{
private:
    int balance;
    int fare;

public:
    SmartCard(int initialBalance, int journeyFare)
    {
        balance = initialBalance;
        fare = journeyFare;
    }

    bool canTravel() const
    {
        return balance - fare >= 50;
    }

    void displayDetails() const
    {
        cout << "Card Balance : Rs " << balance << endl;
        cout << "Fare         : Rs " << fare << endl;

        if (canTravel())
        {
            cout << "Journey      : ALLOWED" << endl;
        }
        else
        {
            cout << "Journey      : NOT ALLOWED" << endl;
        }
    }
};

int main()
{
    cout << "Object-Oriented SmartCard Design" << endl;
    cout << "=================================" << endl;

    SmartCard card(100, 30);

    card.displayDetails();

    return 0;
}