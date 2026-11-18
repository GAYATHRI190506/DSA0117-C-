
#include <iostream>
#include <string>
using namespace std;

// Base class
class Person {
protected:
    string name;
    int id;
    string phone;

public:
    Person(string n, int i, string p)
        : name(n), id(i), phone(p) {}

    void displayPerson() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Phone: " << phone << endl;
    }
};

// Virtual inheritance
class Student : virtual public Person {
protected:
    string programme;
    double cgpa;

public:
    Student(string n, int i, string p, string prog, double c)
        : Person(n, i, p), programme(prog), cgpa(c) {}

    void displayStudent() const {
        cout << "Programme: " << programme << endl;
        cout << "CGPA: " << cgpa << endl;
    }
};

// Virtual inheritance
class Staff : virtual public Person {
protected:
    string department;
    double salary;

public:
    Staff(string n, int i, string p, string d, double s)
        : Person(n, i, p), department(d), salary(s) {}

    void displayStaff() const {
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
    }
};

// Multiple inheritance
class TeachingAssistant : public Student, public Staff {
public:
    TeachingAssistant(string n, int i, string p,
                      string prog, double c,
                      string d, double s)
        : Person(n, i, p),
          Student(n, i, p, prog, c),
          Staff(n, i, p, d, s) {}

    void display() const {
        cout << "\n--- Teaching Assistant ---" << endl;
        displayPerson();
        displayStudent();
        displayStaff();
    }
};

// Hierarchical inheritance
class ResearchScholar : public Student {
private:
    double fellowship;

public:
    ResearchScholar(string n, int i, string p,
                    string prog, double c, double f)
        : Person(n, i, p),
          Student(n, i, p, prog, c),
          fellowship(f) {}

    void display() const {
        cout << "\n--- Research Scholar ---" << endl;
        displayPerson();
        displayStudent();
        cout << "Fellowship: " << fellowship << endl;
    }
};

int main() {
    TeachingAssistant ta(
        "Gayathri", 101, "9876543210",
        "CSE-AI", 9.2, "IT", 35000
    );

    ResearchScholar rs(
        "Kavya", 102, "9876501234",
        "Artificial Intelligence", 9.5, 15000
    );

    ta.display();
    rs.display();

    return 0;
}
