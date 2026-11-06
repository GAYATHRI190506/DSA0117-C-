#include <iostream>
using namespace std;

class Complex
{
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0)
        : real(r), imag(i)
    {
    }

    Complex operator/(const Complex& other) const
    {
        double denominator =
            other.real * other.real +
            other.imag * other.imag;

        if (denominator == 0)
        {
            cout << "Error: Division by zero.\n";
            return Complex();
        }

        return Complex(
            (real * other.real +
             imag * other.imag) / denominator,

            (imag * other.real -
             real * other.imag) / denominator
        );
    }

    friend ostream& operator<<(ostream& out,
                               const Complex& c)
    {
        out << c.real;

        if (c.imag >= 0)
            out << " + " << c.imag << "j";
        else
            out << " - " << -c.imag << "j";

        return out;
    }
};

int main()
{
    Complex numerator(5, 3);
    Complex zero(0, 0);

    cout << "ZERO DIVISION TEST\n";
    cout << "==================\n\n";

    Complex result = numerator / zero;

    cout << "Result: " << result << '\n';

    return 0;
}