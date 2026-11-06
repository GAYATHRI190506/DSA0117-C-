#include <iostream>
#include <iomanip>
using namespace std;

class Money
{
    long long paise;

public:
    explicit Money(long long p = 0)
        : paise(p)
    {
    }

    Money operator+(const Money& other) const
    {
        return Money(paise + other.paise);
    }

    Money operator-(const Money& other) const
    {
        return Money(paise - other.paise);
    }

    friend ostream& operator<<(ostream& out, const Money& money)
    {
        long long value = money.paise;
        bool negative = value < 0;

        if (negative)
            value = -value;

        long long rupees = value / 100;
        long long remainingPaise = value % 100;

        if (negative)
            out << "-";

        out << "Rs."
            << rupees << "."
            << setw(2) << setfill('0')
            << remainingPaise;

        out << setfill(' ');

        return out;
    }
};

int main()
{
    Money a(1250);   // Rs.12.50
    Money b(275);    // Rs.2.75

    Money carry = a + b;

    Money c(500);    // Rs.5.00
    Money d(275);    // Rs.2.75

    Money borrow = c - d;

    cout << "Carry test: "
         << carry << '\n';

    cout << "Borrow test: "
         << borrow << '\n';

    return 0;
}