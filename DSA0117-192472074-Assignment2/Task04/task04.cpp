#include <iostream>
using namespace std;

class Student
{
private:
    int marks[5];

public:
    void inputMarks()
    {
        cout << "Enter 5 marks: ";

        for (int i = 0; i < 5; i++)
        {
            cin >> marks[i];
        }
    }

    int totalMarks()
    {
        int total = 0;

        for (int i = 0; i < 5; i++)
        {
            total += marks[i];
        }

        return total;
    }

    double averageMarks()
    {
        return totalMarks() / 5.0;
    }
};

int main()
{
    Student student;

    student.inputMarks();

    cout << "Total marks = " << student.totalMarks() << '\n';
    cout << "Average marks = " << student.averageMarks() << '\n';

    return 0;
}