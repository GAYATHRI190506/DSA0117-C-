#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main()
{
    int zone;
    long long balance;
    int hour;

    cout << "Metro Smart-Card Input Validation" << endl;
    cout << "==================================" << endl;

    // ---------------------------------------------------------
    // Read and validate zone
    // ---------------------------------------------------------

    cout << "\nEnter zone (1-3): ";

    if (!(cin >> zone))
    {
        cout << "Invalid input: Zone must be an integer." << endl;
        return 0;
    }

    if (zone < 1 || zone > 3)
    {
        cout << "Invalid input: Zone must be between 1 and 3." << endl;
        return 0;
    }

    // ---------------------------------------------------------
    // Read and validate balance
    // ---------------------------------------------------------

    cout << "Enter balance in paise: ";

    if (!(cin >> balance))
    {
        cout << "Invalid input: Balance must be a number." << endl;
        return 0;
    }

    if (balance < 0)
    {
        cout << "Invalid input: Balance cannot be negative." << endl;
        return 0;
    }

    // ---------------------------------------------------------
    // Read and validate hour
    // ---------------------------------------------------------

    cout << "Enter journey hour (0-23): ";

    if (!(cin >> hour))
    {
        cout << "Invalid input: Hour must be an integer." << endl;
        return 0;
    }

    if (hour < 0 || hour > 23)
    {
        cout << "Invalid input: Hour must be between 0 and 23." << endl;
        return 0;
    }

    // ---------------------------------------------------------
    // Determine zone name and fare
    // ---------------------------------------------------------

    string zoneName;
    long long fare;

    switch (zone)
    {
        case 1:
            zoneName = "Inner";
            fare = 1000;
            break;

        case 2:
            zoneName = "Middle";
            fare = 2000;
            break;

        case 3:
            zoneName = "Outer";
            fare = 3000;
            break;

        default:
            cout << "Invalid zone." << endl;
            return 0;
    }

    // ---------------------------------------------------------
    // Peak hour check
    // ---------------------------------------------------------

    bool peakHour =
        (hour >= 8 && hour < 10) ||
        (hour >= 17 && hour < 20);

    if (peakHour)
    {
        fare += fare * 20 / 100;
    }

    // ---------------------------------------------------------
    // Display formatted output
    // ---------------------------------------------------------

    cout << "\nMetro Fare Summary" << endl;
    cout << "==================" << endl;

    cout << left << setw(25) << "Zone"
         << ": " << zoneName << endl;

    cout << left << setw(25) << "Balance"
         << ": Rs " << fixed << setprecision(2)
         << balance / 100.0 << endl;

    cout << left << setw(25) << "Hour"
         << ": " << hour << endl;

    cout << left << setw(25) << "Peak Hour"
         << ": " << (peakHour ? "Yes" : "No") << endl;

    cout << left << setw(25) << "Final Fare"
         << ": Rs " << fare / 100.0 << endl;

    // ---------------------------------------------------------
    // Journey validation
    // ---------------------------------------------------------

    if (balance - fare >= 5000)
    {
        cout << left << setw(25) << "Journey Status"
             << ": ALLOWED" << endl;
    }
    else
    {
        cout << left << setw(25) << "Journey Status"
             << ": NOT ALLOWED" << endl;
        cout << "Minimum balance of Rs 50 must remain after fare."
             << endl;
    }

    return 0;
}