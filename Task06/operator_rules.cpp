#include <iostream>
#include <string>
using namespace std;

class Demo
{
public:
    int value;

    Demo(int v = 0) : value(v) {}

    // Valid operator overloads
    Demo operator+(const Demo& other) const
    {
        return Demo(value + other.value);
    }

    bool operator==(const Demo& other) const
    {
        return value == other.value;
    }
};

int main()
{
    Demo a(10);
    Demo b(20);

    Demo c = a + b;

    cout << "a + b = " << c.value << '\n';
    cout << "a == b : "
         << (a == b ? "true" : "false") << '\n';

    string s1 = "Hello";
    string s2 = "Hello";

    cout << "std::string comparison: "
         << (s1 == s2 ? "equal" : "not equal") << '\n';

    cout << "\nNon-overloadable operators in C++:\n";
    cout << "::  .  .*  ?:  sizeof\n";

    return 0;
}