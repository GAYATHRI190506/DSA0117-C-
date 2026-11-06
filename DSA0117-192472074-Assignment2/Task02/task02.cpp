#include <iostream>

int& getValue(int& x)
{
    return x;
}

// Dangerous: returning reference to a local variable
int& dangerous()
{
    int local = 50;
    return local;
}

int main()
{
    int number = 50;

    getValue(number) = 100;

    std::cout << "Number = " << number << '\n';

    // Do NOT use dangerous() here.
    // The reference would refer to a destroyed local variable.

    return 0;
}