#include <iostream>
using namespace std;

class Student
{
private:
    int rollNo;
    string name;
    static int count;

public:
    Student(int r, string n)
    {
        rollNo = r;
        name = n;
        count++;
    }

    void display()
    {
        cout << "Roll No: " << rollNo
             << ", Name: " << name << '\n';
    }

    static int getCount()
    {
        return count;
    }
};

// Definition of static data member
int Student::count = 0;

int main()
{
    Student students[3] = {
        Student(101, "Gayathri"),
        Student(102, "Harini"),
        Student(103, "Rithika")
    };

    cout << "Number of students: "
         << Student::getCount() << '\n';

    cout << "\nStudent Details:\n";

    for (int i = 0; i < 3; i++)
    {
        students[i].display();
    }

    return 0;
}