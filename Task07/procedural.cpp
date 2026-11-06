#include <iostream>

using namespace std;

const int MIN_BALANCE = 50;

// Global variables
int cardBalance = 100;
int fare = 30;

// Procedural function
bool canTravel()
{
    return cardBalance - fare >= MIN_BALANCE;
}

void displayCardDetails()
{
    cout << "Card Balance : Rs " << cardBalance << endl;
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

int main()
{
    cout << "Procedural SmartCard Design" << endl;
    cout << "===========================" << endl;

    displayCardDetails();

    return 0;
}