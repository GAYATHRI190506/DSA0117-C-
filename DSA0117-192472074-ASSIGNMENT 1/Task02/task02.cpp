#include <iostream>

using namespace std;

// Fare constants
constexpr long long INNER_FARE_PAISE = 1000;   // Rs 10
constexpr long long MIDDLE_FARE_PAISE = 2000;  // Rs 20
constexpr long long OUTER_FARE_PAISE = 3000;   // Rs 30

constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr long long MIN_BALANCE_PAISE = 5000;  // Rs 50

enum class Zone
{
    Inner,
    Middle,
    Outer
};

int main()
{
    Zone selectedZone = Zone::Outer;

    long long baseFare = 0;

    switch (selectedZone)
    {
        case Zone::Inner:
            baseFare = INNER_FARE_PAISE;
            break;

        case Zone::Middle:
            baseFare = MIDDLE_FARE_PAISE;
            break;

        case Zone::Outer:
            baseFare = OUTER_FARE_PAISE;
            break;
    }

    cout << "Metro Fare Information" << endl;
    cout << "Base fare: Rs " << baseFare / 100 << "."
         << baseFare % 100 << endl;

    cout << "Peak surcharge: "
         << PEAK_SURCHARGE_PERCENT << "%" << endl;

    cout << "Minimum balance required: Rs "
         << MIN_BALANCE_PAISE / 100 << endl;

    return 0;
}