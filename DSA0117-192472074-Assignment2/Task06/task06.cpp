#include <iostream>
using namespace std;

class Student
{
private:
    int marks;

public:
    Student(int m)
    {
        marks = m;
    }

    // Friend function declaration
    friend void compareMarks(const Student& s1, const Student& s2);
};

// Friend function
void compareMarks(const Student& s1, const Student& s2)
{
    if (s1.marks > s2.marks)
        cout << "Student 1 has higher marks." << '\n';
    else if (s2.marks > s1.marks)
        cout << "Student 2 has higher marks." << '\n';
    else
        cout << "Both students have equal marks." << '\n';
}

// Inline function
inline int calculateBonus(int marks)
{
    return marks >= 90 ? 10 : 5;
}

int main()
{
    Student s1(85);
    Student s2(92);

    compareMarks(s1, s2);

    cout << "Bonus for Student 1: "
         << calculateBonus(85) << '\n';

    cout << "Bonus for Student 2: "
         << calculateBonus(92) << '\n';

    return 0;
}