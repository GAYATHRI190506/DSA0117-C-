#include <iostream>

using namespace std;

int main()
{
    cout << "Metro Fare System - Operators and Expressions" << endl;
    cout << "============================================" << endl;

    // ---------------------------------------------------------
    // 1. Arithmetic operators
    // ---------------------------------------------------------

    int fare = 30;
    int journeys = 3;

    cout << "\n1. Arithmetic Operators" << endl;
    cout << "Fare                  : Rs " << fare << endl;
    cout << "Journeys              : " << journeys << endl;
    cout << "Addition              : " << fare + journeys << endl;
    cout << "Subtraction           : " << fare - journeys << endl;
    cout << "Multiplication        : " << fare * journeys << endl;
    cout << "Division              : " << fare / journeys << endl;
    cout << "Remainder             : " << fare % journeys << endl;

    // ---------------------------------------------------------
    // 2. Relational operators
    // ---------------------------------------------------------

    int balance = 100;
    int requiredBalance = 50;

    cout << "\n2. Relational Operators" << endl;
    cout << "Balance               : Rs " << balance << endl;
    cout << "Required balance      : Rs " << requiredBalance << endl;

    cout << "balance > required    : "
         << (balance > requiredBalance) << endl;

    cout << "balance < required    : "
         << (balance < requiredBalance) << endl;

    cout << "balance >= required   : "
         << (balance >= requiredBalance) << endl;

    cout << "balance == required   : "
         << (balance == requiredBalance) << endl;

    cout << "balance != required   : "
         << (balance != requiredBalance) << endl;

    // ---------------------------------------------------------
    // 3. Logical operators
    // ---------------------------------------------------------

    bool sufficientBalance = balance >= requiredBalance;
    bool validCard = true;

    cout << "\n3. Logical Operators" << endl;

    cout << "Sufficient balance    : "
         << sufficientBalance << endl;

    cout << "Valid card            : "
         << validCard << endl;

    cout << "AND (&&)              : "
         << (sufficientBalance && validCard) << endl;

    cout << "OR (||)               : "
         << (sufficientBalance || validCard) << endl;

    cout << "NOT (!) valid card    : "
         << (!validCard) << endl;

    // ---------------------------------------------------------
    // 4. Assignment operators
    // ---------------------------------------------------------

    int amount = 100;

    cout << "\n4. Assignment Operators" << endl;
    cout << "Initial amount        : " << amount << endl;

    amount += 20;
    cout << "After += 20           : " << amount << endl;

    amount -= 10;
    cout << "After -= 10           : " << amount << endl;

    amount *= 2;
    cout << "After *= 2            : " << amount << endl;

    amount /= 2;
    cout << "After /= 2            : " << amount << endl;

    // ---------------------------------------------------------
    // 5. Increment and decrement operators
    // ---------------------------------------------------------

    int count = 5;

    cout << "\n5. Increment and Decrement" << endl;
    cout << "Initial count         : " << count << endl;

    cout << "Post-increment        : " << count++ << endl;
    cout << "After post-increment  : " << count << endl;

    cout << "Pre-increment         : " << ++count << endl;

    cout << "Post-decrement        : " << count-- << endl;
    cout << "After post-decrement  : " << count << endl;

    cout << "Pre-decrement         : " << --count << endl;

    // ---------------------------------------------------------
    // 6. Operator precedence
    // ---------------------------------------------------------

    int a = 10;
    int b = 5;
    int c = 2;

    int expression1 = a + b * c;
    int expression2 = (a + b) * c;

    cout << "\n6. Operator Precedence" << endl;

    cout << "a                    : " << a << endl;
    cout << "b                    : " << b << endl;
    cout << "c                    : " << c << endl;

    cout << "a + b * c            : "
         << expression1 << endl;

    cout << "(a + b) * c          : "
         << expression2 << endl;

    // ---------------------------------------------------------
    // 7. Peak fare calculation
    // ---------------------------------------------------------

    int baseFare = 30;
    int surchargePercent = 20;

    int surcharge = baseFare * surchargePercent / 100;
    int peakFare = baseFare + surcharge;

    cout << "\n7. Peak Fare Calculation" << endl;

    cout << "Base fare            : Rs "
         << baseFare << endl;

    cout << "Surcharge percentage  : "
         << surchargePercent << "%" << endl;

    cout << "Surcharge             : Rs "
         << surcharge << endl;

    cout << "Peak fare             : Rs "
         << peakFare << endl;

    // ---------------------------------------------------------
    // 8. Combined expression
    // ---------------------------------------------------------

    int cardBalance = 100;
    int fareAmount = 30;
    bool canTravel =
        cardBalance >= 50 && cardBalance >= fareAmount;

    cout << "\n8. Combined Fare Validation" << endl;

    cout << "Card balance          : Rs "
         << cardBalance << endl;

    cout << "Fare amount           : Rs "
         << fareAmount << endl;

    cout << "Can travel            : "
         << canTravel << endl;

    return 0;
}