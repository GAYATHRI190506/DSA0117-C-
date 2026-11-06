#include <iostream>

using namespace std;

// Fare values in paise
constexpr long long INNER_FARE = 1000;      // Rs 10
constexpr long long MIDDLE_FARE = 2000;     // Rs 20
constexpr long long OUTER_FARE = 3000;      // Rs 30

constexpr int PEAK_SURCHARGE = 20;          // 20%
constexpr long long MIN_BALANCE = 5000;     // Rs 50

// Function to calculate fare based on zone
long long getBaseFare(int zone)
{
    switch (zone)
    {
        case 1:
            return INNER_FARE;

        case 2:
            return MIDDLE_FARE;

        case 3:
            return OUTER_FARE;

        default:
            return 0;
    }
}

// Function to check whether the journey is allowed
bool canTravel(long long balance, long long fare)
{
    return balance - fare >= MIN_BALANCE;
}

// Function to calculate final fare
long long calculateFare(long long baseFare, bool peakHour)
{
    if (peakHour)
    {
        long long surcharge =
            baseFare * PEAK_SURCHARGE / 100;

        return baseFare + surcharge;
    }

    return baseFare;
}

int main()
{
    int zone;
    long long balance;
    int hour;
    char passengerType;

    cout << "City Metro Smart-Card Fare System" << endl;
    cout << "=================================" << endl;

    cout << "\nEnter zone (1-Inner, 2-Middle, 3-Outer): ";
    cin >> zone;

    cout << "Enter card balance in paise: ";
    cin >> balance;

    cout << "Enter journey hour (0-23): ";
    cin >> hour;

    cout << "Enter passenger type (R-Regular, S-Student, N-Senior): ";
    cin >> passengerType;

    // ---------------------------------------------------------
    // Get base fare
    // ---------------------------------------------------------

    long long baseFare = getBaseFare(zone);

    if (baseFare == 0)
    {
        cout << "\nInvalid zone." << endl;
        return 0;
    }

    // ---------------------------------------------------------
    // Determine peak hour
    // Peak: 8-10 AM and 5-8 PM
    // ---------------------------------------------------------

    bool peakHour =
        (hour >= 8 && hour < 10) ||
        (hour >= 17 && hour < 20);

    // ---------------------------------------------------------
    // Calculate fare with peak surcharge
    // ---------------------------------------------------------

    long long fare = calculateFare(baseFare, peakHour);

    // ---------------------------------------------------------
    // Apply passenger concession
    // Student and senior get 50% concession
    // ---------------------------------------------------------

    if (passengerType == 'S' ||
        passengerType == 's' ||
        passengerType == 'N' ||
        passengerType == 'n')
    {
        fare = fare / 2;
    }

    // ---------------------------------------------------------
    // Display fare information
    // ---------------------------------------------------------

    cout << "\nFare Details" << endl;
    cout << "============" << endl;

    cout << "Zone                  : ";

    switch (zone)
    {
        case 1:
            cout << "Inner";
            break;

        case 2:
            cout << "Middle";
            break;

        case 3:
            cout << "Outer";
            break;
    }

    cout << endl;

    cout << "Base fare             : Rs "
         << baseFare / 100 << endl;

    cout << "Peak hour             : "
         << (peakHour ? "Yes" : "No") << endl;

    cout << "Final fare            : Rs "
         << fare / 100 << endl;

    cout << "Remaining balance     : Rs "
         << (balance - fare) / 100 << endl;

    // ---------------------------------------------------------
    // Validate journey
    // ---------------------------------------------------------

    if (canTravel(balance, fare))
    {
        cout << "Journey status        : ALLOWED" << endl;
    }
    else
    {
        cout << "Journey status        : NOT ALLOWED" << endl;
        cout << "Reason                : Minimum balance of Rs 50 "
             << "must remain after fare." << endl;
    }

    return 0;
}