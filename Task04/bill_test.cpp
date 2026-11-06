#include <iostream>
using namespace std;

class Money
{
    long long paise;

public:
    explicit Money(long long p = 0) : paise(p) {}

    Money operator+(const Money& other) const
    {
        return Money(paise + other.paise);
    }

    Money operator-(const Money& other) const
    {
        return Money(paise - other.paise);
    }

    Money& operator+=(const Money& other)
    {
        paise += other.paise;
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Money& money)
    {
        long long value = money.paise;
        bool negative = value < 0;

        if (negative)
            value = -value;

        if (negative)
            out << "-";

        out << "Rs."
            << value / 100
            << "."
            << (value % 100 < 10 ? "0" : "")
            << value % 100;

        return out;
    }
};

int main()
{
    Money item1(1250);   // Rs.12.50
    Money item2(275);    // Rs.2.75
    Money item3(500);    // Rs.5.00

    Money total = item1 + item2 + item3;

    cout << "Item 1: " << item1 << '\n';
    cout << "Item 2: " << item2 << '\n';
    cout << "Item 3: " << item3 << '\n';
    cout << "Total Bill: " << total << '\n';

    return 0;
}