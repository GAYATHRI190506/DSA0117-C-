#include <iostream>
using namespace std;

// Function using default arguments
int scholarship(int marks, int bonus = 0)
{
    return marks + bonus;
}

// Function overloading
double scholarship(double marks)
{
    return marks;
}

int main()
{
    cout << "Scholarship with marks only: "
         << scholarship(80) << '\n';

    cout << "Scholarship with marks and bonus: "
         << scholarship(80, 10) << '\n';

    cout << "Scholarship with decimal marks: "
         << scholarship(85.5) << '\n';

    return 0;
}