#include <iostream>
#include <iomanip>
using namespace std;

class Money
{
private:
    long long paise;

public:
    // Constructor
    explicit Money(long long p = 0)
        : paise(p)
    {
    }

    // Addition
    Money operator+(const Money& other) const
    {
        return Money(paise + other.paise);
    }

    // Subtraction
    Money operator-(const Money& other) const
    {
        return Money(paise - other.paise);
    }

    // Compound addition
    Money& operator+=(const Money& other)
    {
        paise += other.paise;
        return *this;
    }

    // Equality
    bool operator==(const Money& other) const
    {
        return paise == other.paise;
    }

    // Less than
    bool operator<(const Money& other) const
    {
        return paise < other.paise;
    }

    // Output operator
    friend ostream& operator<<(ostream& out, const Money& money)
    {
        long long absolutePaise =
            money.paise < 0 ? -money.paise : money.paise;

        long long rupees = absolutePaise / 100;
        long long remainingPaise = absolutePaise % 100;

        if (money.paise < 0)
        {
            out << "-";
        }

        out << "Rs."
            << rupees
            << "."
            << setw(2)
            << setfill('0')
            << remainingPaise;

        out << setfill(' ');

        return out;
    }

    // Input operator
    friend istream& operator>>(istream& in, Money& money)
    {
        long long rupees;
        long long p;

        in >> rupees >> p;

        money.paise = rupees * 100 + p;

        return in;
    }
};

int main()
{
    cout << "MONEY OPERATOR OVERLOADING\n";
    cout << "==========================\n\n";

    Money m1(1250);   // Rs.12.50
    Money m2(275);    // Rs.2.75

    cout << "m1 = " << m1 << '\n';
    cout << "m2 = " << m2 << '\n';

    Money sum = m1 + m2;
    cout << "m1 + m2 = " << sum << '\n';

    Money difference = m1 - m2;
    cout << "m1 - m2 = " << difference << '\n';

    m1 += m2;
    cout << "m1 after += m2 = " << m1 << '\n';

    cout << "m1 == m2 : "
         << (m1 == m2 ? "true" : "false") << '\n';

    cout << "m2 < m1 : "
         << (m2 < m1 ? "true" : "false") << '\n';

    Money negative = Money(250) - Money(500);
    cout << "Negative result = " << negative << '\n';

    return 0;
}