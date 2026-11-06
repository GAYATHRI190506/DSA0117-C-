#include <iostream>
#include <iomanip>
#include <climits>
#include <cfloat>
#include <limits>
#include <typeinfo>

using namespace std;

int main()
{
    // ---------------------------------------------------------
    // 1. Declare different C++ data types
    // ---------------------------------------------------------

    bool boolValue = true;
    char charValue = 'A';
    int intValue = 1000;
    long long longLongValue = 9000000000LL;
    unsigned int unsignedValue = 4000000000U;
    float floatValue = 10.5f;
    double doubleValue = 20.75;
    auto autoValue = 5000LL;

    // ---------------------------------------------------------
    // 2. Display sizeof() for different data types
    // ---------------------------------------------------------

    cout << "C++ Data Type Information" << endl;
    cout << "=========================" << endl;

    cout << left << setw(18) << "Data Type"
         << setw(12) << "Size(bytes)" << endl;

    cout << left << setw(18) << "bool"
         << sizeof(boolValue) << endl;

    cout << left << setw(18) << "char"
         << sizeof(charValue) << endl;

    cout << left << setw(18) << "int"
         << sizeof(intValue) << endl;

    cout << left << setw(18) << "long long"
         << sizeof(longLongValue) << endl;

    cout << left << setw(18) << "unsigned int"
         << sizeof(unsignedValue) << endl;

    cout << left << setw(18) << "float"
         << sizeof(floatValue) << endl;

    cout << left << setw(18) << "double"
         << sizeof(doubleValue) << endl;

    cout << left << setw(18) << "auto"
         << sizeof(autoValue) << endl;

    // ---------------------------------------------------------
    // 3. Display important ranges
    // ---------------------------------------------------------

    cout << "\nData Type Ranges" << endl;
    cout << "================" << endl;

    cout << "int minimum       : " << INT_MIN << endl;
    cout << "int maximum       : " << INT_MAX << endl;

    cout << "unsigned int max  : " << UINT_MAX << endl;

    cout << "long long minimum : "
         << numeric_limits<long long>::min() << endl;

    cout << "long long maximum : "
         << numeric_limits<long long>::max() << endl;

    cout << "float maximum     : "
         << FLT_MAX << endl;

    cout << "double maximum    : "
         << DBL_MAX << endl;

    // ---------------------------------------------------------
    // 4. Metro fare using integer paise
    // ---------------------------------------------------------

    cout << "\nMetro Fare Representation" << endl;
    cout << "=========================" << endl;

    long long farePaise = 3000;       // Rs 30
    long long journeys = 3000000;     // 3 million journeys

    long long totalPaise = farePaise * journeys;

    cout << "Fare per journey       : Rs "
         << farePaise / 100 << endl;

    cout << "Number of journeys     : "
         << journeys << endl;

    cout << "Total collection       : Rs "
         << totalPaise / 100 << endl;

    cout << "Total in paise         : "
         << totalPaise << endl;

    // Check whether the total fits in a signed int
    if (totalPaise > INT_MAX)
    {
        cout << "int compatibility      : Total paise exceeds INT_MAX" << endl;
        cout << "Recommended type       : long long" << endl;
    }
    else
    {
        cout << "int compatibility      : Total paise fits in int" << endl;
    }

    // ---------------------------------------------------------
    // 5. Type compatibility and implicit conversion
    // ---------------------------------------------------------

    cout << "\nType Compatibility" << endl;
    cout << "==================" << endl;

    int number = 10;
    double decimalNumber = 2.5;

    auto mixedResult = number + decimalNumber;

    cout << "int value              : " << number << endl;
    cout << "double value            : " << decimalNumber << endl;
    cout << "int + double result     : " << mixedResult << endl;

    cout << "Result type             : "
         << typeid(mixedResult).name() << endl;

    bool status = true;
    int boolConverted = status;

    cout << "bool value              : " << status << endl;
    cout << "bool converted to int  : " << boolConverted << endl;

    // ---------------------------------------------------------
    // 6. Floating-point precision demonstration
    // ---------------------------------------------------------

    cout << "\nFloating-Point Precision" << endl;
    cout << "========================" << endl;

    double repeatedAmount = 0.0;
    const int count = 10;

    for (int i = 0; i < count; i++)
    {
        repeatedAmount += 0.1;
    }

    double expectedAmount = 1.0;
    double error = repeatedAmount - expectedAmount;

    cout << fixed << setprecision(17);

    cout << "Adding 0.1 ten times   : "
         << repeatedAmount << endl;

    cout << "Expected value         : "
         << expectedAmount << endl;

    cout << "Floating-point error   : "
         << error << endl;

    // ---------------------------------------------------------
    // 7. Final recommendation
    // ---------------------------------------------------------

    cout << "\nRecommended Data Types" << endl;
    cout << "======================" << endl;

    cout << "Money values           : long long (paise)" << endl;
    cout << "Journey count          : long long" << endl;
    cout << "Zone / small values    : int or enum class" << endl;
    cout << "Boolean status         : bool" << endl;
    cout << "Text characters        : char" << endl;
    cout << "Decimal calculations   : double when required" << endl;

    return 0;
}