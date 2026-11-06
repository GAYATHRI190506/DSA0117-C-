#include <iostream>
using namespace std;

enum class Zone
{
    Inner = 1,
    Middle,
    Outer,
    Airport
};

class FareSystem
{
public:
    static int getBaseFare(Zone zone)
    {
        switch (zone)
        {
            case Zone::Inner:   return 1000;
            case Zone::Middle:  return 2000;
            case Zone::Outer:   return 3000;
            case Zone::Airport: return 6000;
        }
        return 0;
    }

    static int calculateFare(Zone zone, bool weekend, bool peak)
    {
        int fare = getBaseFare(zone);

        // Weekend discount and peak surcharge are not combined.
        if (weekend)
        {
            fare = fare - (fare * 10 / 100);
        }
        else if (peak)
        {
            fare = fare + (fare * 20 / 100);
        }

        return fare;
    }
};

class MonthlyPass
{
private:
    Zone zone1;
    Zone zone2;

public:
    MonthlyPass(Zone first, Zone second)
        : zone1(first), zone2(second)
    {
    }

    bool covers(Zone zone) const
    {
        return zone == zone1 || zone == zone2;
    }
};

void displayFare(const string& description, int fare)
{
    cout << description << " : Rs "
         << fare / 100 << "." << fare % 100 << endl;
}

int main()
{
    cout << "METRO SMART-CARD SYSTEM - DESIGN CHALLENGE" << endl;
    cout << "===========================================" << endl;

    cout << "\n1. Extended Zone Fare" << endl;
    cout << "----------------------" << endl;

    displayFare("Inner Zone", FareSystem::getBaseFare(Zone::Inner));
    displayFare("Middle Zone", FareSystem::getBaseFare(Zone::Middle));
    displayFare("Outer Zone", FareSystem::getBaseFare(Zone::Outer));
    displayFare("Airport Zone", FareSystem::getBaseFare(Zone::Airport));

    cout << "\n2. Weekend Discount" << endl;
    cout << "-------------------" << endl;

    int weekendFare = FareSystem::calculateFare(Zone::Airport, true, false);
    displayFare("Airport weekend fare (10% discount)", weekendFare);

    cout << "\n3. Peak Hour Fare" << endl;
    cout << "-----------------" << endl;

    int peakFare = FareSystem::calculateFare(Zone::Airport, false, true);
    displayFare("Airport peak fare (20% surcharge)", peakFare);

    cout << "\n4. Weekend + Peak Rule" << endl;
    cout << "----------------------" << endl;

    int weekendPeakFare = FareSystem::calculateFare(Zone::Airport, true, true);
    displayFare("Weekend + peak fare", weekendPeakFare);
    cout << "Weekend discount is applied instead of peak surcharge." << endl;
    cout << "The two rules are NOT combined." << endl;

    cout << "\n5. Monthly Pass" << endl;
    cout << "---------------" << endl;

    MonthlyPass pass(Zone::Inner, Zone::Middle);

    cout << "Monthly pass zones: Inner + Middle" << endl;
    cout << "Inner journey  : "
         << (pass.covers(Zone::Inner) ? "COVERED" : "NOT COVERED") << endl;
    cout << "Middle journey : "
         << (pass.covers(Zone::Middle) ? "COVERED" : "NOT COVERED") << endl;
    cout << "Outer journey  : "
         << (pass.covers(Zone::Outer) ? "COVERED" : "NOT COVERED") << endl;
    cout << "Airport journey: "
         << (pass.covers(Zone::Airport) ? "COVERED" : "NOT COVERED") << endl;

    cout << "\n6. Design Decision" << endl;
    cout << "------------------" << endl;
    cout << "Decision: MODIFY THE EXISTING OOP DESIGN." << endl;
    cout << "Reason: The original design is reusable, but new zone," << endl;
    cout << "weekend discount and monthly-pass requirements need extensions." << endl;

    cout << "\nResult: DESIGN CHALLENGE SUCCESSFULLY IMPLEMENTED" << endl;

    return 0;
}