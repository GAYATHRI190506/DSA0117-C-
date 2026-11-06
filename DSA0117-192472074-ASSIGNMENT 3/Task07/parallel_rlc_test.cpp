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

    Complex ZR(R, 0);
    Complex ZL(0, omega * L);
    Complex ZC(0, -1.0 / (omega * C));

    // Parallel impedance:
    // 1/Zp = 1/ZR + 1/ZL + 1/ZC

    Complex one(1, 0);

    Complex admittanceR = one / ZR;
    Complex admittanceL = one / ZL;
    Complex admittanceC = one / ZC;

    Complex totalAdmittance =
        admittanceR + admittanceL + admittanceC;

    Complex Zparallel =
        one / totalAdmittance;

    cout << "PARALLEL RLC IMPEDANCE TEST\n";
    cout << "===========================\n\n";

    cout << "Resistance R = " << R << " ohms\n";
    cout << "Inductance L = " << L << " H\n";
    cout << "Capacitance C = " << C << " F\n";
    cout << "Frequency f = " << f << " Hz\n\n";

    cout << "Parallel RLC impedance = "
         << Zparallel << " ohms\n";

    return 0;
}