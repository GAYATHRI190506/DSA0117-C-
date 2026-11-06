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

    friend istream& operator>>(istream& in, Money& money)
    {
        long long rupees;
        char dot;
        int paisePart;

        in >> rupees >> dot >> paisePart;

        if (in && dot == '.')
        {
            money.paise = rupees * 100 + paisePart;
        }

        return in;
    }
};

int main()
{
    Money m;

    cout << "Enter money (example: 25.50): ";
    cin >> m;

    cout << "You entered: " << m << '\n';

    return 0;
}