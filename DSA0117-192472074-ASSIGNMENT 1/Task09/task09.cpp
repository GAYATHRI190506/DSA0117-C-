#include <iostream>
#include <iomanip>

using namespace std;

long long getBaseFare(int zone)
{
    switch (zone)
    {
        case 1:
            return 1000;   // Rs 10

        case 2:
            return 2000;   // Rs 20

        case 3:
            return 3000;   // Rs 30

        default:
            return 0;
    }
}

bool isPeakHour(int hour)
{
    return (hour >= 8 && hour < 10) ||
           (hour >= 17 && hour < 20);
}

long long calculateFare(int zone, int hour, char passengerType)
{
    long long fare = getBaseFare(zone);

    if (fare == 0)
    {
        return 0;
    }

    // Peak-hour surcharge
    if (isPeakHour(hour))
    {
        fare += fare * 20 / 100;
    }

    // Student and senior concession
    if (passengerType == 'S' ||
        passengerType == 's' ||
        passengerType == 'N' ||
        passengerType == 'n')
    {
        fare /= 2;
    }

    return fare;
}

bool canTravel(long long balance, long long fare)
{
    return balance - fare >= 5000;
}

int main()
{
    int zone;
    long long balance;
    int hour;
    char passengerType;

    cout << "Metro Smart-Card Testing System" << endl;
    cout << "================================" << endl;

    cout << "\nEnter zone (1-3): ";
    cin >> zone;

    cout << "Enter balance in paise: ";
    cin >> balance;

    cout << "Enter hour (0-23): ";
    cin >> hour;

    cout << "Enter passenger type (R/S/N): ";
    cin >> passengerType;

    long long baseFare = getBaseFare(zone);

    if (baseFare == 0)
    {
        cout << "\nInvalid zone." << endl;
        return 0;
    }

    long long finalFare =
        calculateFare(zone, hour, passengerType);

    cout << "\nTest Result" << endl;
    cout << "===========" << endl;

    cout << left << setw(25)
         << "Zone" << ": " << zone << endl;

    cout << left << setw(25)
         << "Base Fare" << ": Rs "
         << fixed << setprecision(2)
         << baseFare / 100.0 << endl;

    cout << left << setw(25)
         << "Peak Hour" << ": "
         << (isPeakHour(hour) ? "Yes" : "No")
         << endl;

    cout << left << setw(25)
         << "Passenger Type" << ": "
         << passengerType << endl;

    cout << left << setw(25)
         << "Final Fare" << ": Rs "
         << finalFare / 100.0 << endl;

    cout << left << setw(25)
         << "Remaining Balance" << ": Rs "
         << (balance - finalFare) / 100.0
         << endl;

    if (canTravel(balance, finalFare))
    {
        cout << left << setw(25)
             << "Journey Status"
             << ": ALLOWED" << endl;
    }
    else
    {
        cout << left << setw(25)
             << "Journey Status"
             << ": NOT ALLOWED" << endl;
    }

    return 0;
}