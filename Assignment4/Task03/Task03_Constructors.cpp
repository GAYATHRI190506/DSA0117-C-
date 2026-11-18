
#include <iostream>
#include <string>
using namespace std;

// Member class
class Address {
private:
    string city;
    int pinCode;

public:
    Address(string c, int p)
        : city(c), pinCode(p) {}

    void display() const {
        cout << city << "-" << pinCode << endl;
    }
};

// Base class
class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a)
        : name(n), age(a) {}

    void displayPerson() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Derived class with composition
class Student : public Person {
private:
    long long regNo;
    Address home;

public:
    Student(string n, int a, long long r,
            string city, int pin)
        : Person(n, a),
          regNo(r),
          home(city, pin) {}

    void display() const {
        cout << "\n--- Student Details ---" << endl;
        displayPerson();
        cout << "Register Number: " << regNo << endl;
        cout << "Address: ";
        home.display();
    }
};

// Constructor and destructor order demonstration
class Vehicle {
public:
    Vehicle() {
        cout << "Vehicle ";
    }

    virtual ~Vehicle() {
        cout << "~Vehicle ";
    }
};

class Engine {
public:
    Engine() {
        cout << "Engine ";
    }

    ~Engine() {
        cout << "~Engine ";
    }
};

class Car : public Vehicle {
private:
    Engine engine;

public:
    Car() {
        cout << "Car ";
    }

    ~Car() {
        cout << "~Car ";
    }
};

int main() {
    Student s("Kavya", 19, 192311001,
              "Salem", 636001);

    s.display();

    cout << "\n\nConstructor and Destructor Order:" << endl;

    {
        Car c;
    }

    cout << endl;

    return 0;
}
