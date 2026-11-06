#include <iostream>
#include <cmath>
#include <iomanip>
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

    Complex operator+(const Complex& other) const
    {
        return Complex(real + other.real,
                       imag + other.imag);
    }

    Complex operator-(const Complex& other) const
    {
        return Complex(real - other.real,
                       imag - other.imag);
    }

    Complex operator*(const Complex& other) const
    {
        return Complex(
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        );
    }

    Complex operator/(const Complex& other) const
    {
        double denominator =
            other.real * other.real +
            other.imag * other.imag;

        if (denominator == 0)
            return Complex();

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
    const double PI = 3.141592653589793;

    double R = 10.0;
    double L = 0.1;
    double C = 0.001;
    double f = 50.0;

    double omega = 2 * PI * f;

    // Inductive impedance: jωL
    Complex ZL(0, omega * L);

    // Capacitive impedance: -j/(ωC)
    Complex ZC(0, -1.0 / (omega * C));

    // Resistor impedance: R
    Complex ZR(R, 0);

    // Series RLC: Z = R + jωL - j/(ωC)
    Complex Zseries = ZR + ZL + ZC;

    cout << "RLC IMPEDANCE TEST\n";
    cout << "==================\n\n";

    cout << "Resistance R = " << R << " ohms\n";
    cout << "Inductance L = " << L << " H\n";
    cout << "Capacitance C = " << C << " F\n";
    cout << "Frequency f = " << f << " Hz\n\n";

    cout << "Inductive impedance ZL = "
         << ZL << " ohms\n";

    cout << "Capacitive impedance ZC = "
         << ZC << " ohms\n";

    cout << "Series RLC impedance = "
         << Zseries << " ohms\n";

    return 0;
}