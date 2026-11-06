#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Complex
{
private:
    double real;
    double imag;

public:
    // Default constructor
    Complex()
        : real(0), imag(0)
    {
    }

    // Constructor from real number
    Complex(double r)
        : real(r), imag(0)
    {
    }

    // Constructor from real and imaginary parts
    Complex(double r, double i)
        : real(r), imag(i)
    {
    }

    // Addition
    Complex operator+(const Complex& other) const
    {
        return Complex(real + other.real,
                       imag + other.imag);
    }

    // Subtraction
    Complex operator-(const Complex& other) const
    {
        return Complex(real - other.real,
                       imag - other.imag);
    }

    // Multiplication
    Complex operator*(const Complex& other) const
    {
        return Complex(
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        );
    }

    // Division
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

    // Equality
    bool operator==(const Complex& other) const
    {
        const double EPSILON = 1e-9;

        return fabs(real - other.real) < EPSILON &&
               fabs(imag - other.imag) < EPSILON;
    }

    // Stream output
    friend ostream& operator<<(ostream& out,
                               const Complex& c)
    {
        out << fixed << setprecision(2)
            << c.real;

        if (c.imag >= 0)
            out << " + " << c.imag << "j";
        else
            out << " - " << fabs(c.imag) << "j";

        return out;
    }
};

int main()
{
    cout << "COMPLEX NUMBER OPERATOR TEST\n";
    cout << "============================\n\n";

    Complex c1(3, 4);
    Complex c2(1, 2);

    cout << "c1 = " << c1 << '\n';
    cout << "c2 = " << c2 << '\n';

    cout << "c1 + c2 = " << c1 + c2 << '\n';
    cout << "c1 - c2 = " << c1 - c2 << '\n';
    cout << "c1 * c2 = " << c1 * c2 << '\n';
    cout << "c1 / c2 = " << c1 / c2 << '\n';

    cout << "c1 == c2 : "
         << (c1 == c2 ? "true" : "false") << '\n';

    Complex c3(3, 4);

    cout << "c1 == c3 : "
         << (c1 == c3 ? "true" : "false") << '\n';

    return 0;
}