#include <iostream>
#include <string>
using namespace std;

// Abstract base class
class Bill {
protected:
    string patient;

public:
    Bill(const string& p) : patient(p) {}

    virtual ~Bill() = default;

    virtual double total() const = 0;

    virtual string type() const {
        return "Bill";
    }

    void print() const {
        cout << type() << " - Patient: " << patient
             << ", Total: " << total() << '\n';
    }
};

// Outpatient bill
class OutPatientBill : public Bill {
private:
    double consultation;
    double tests;

public:
    OutPatientBill(const string& p, double c, double t)
        : Bill(p), consultation(c), tests(t) {}

    double total() const override {
        return consultation + tests;
    }

    string type() const override {
        return "OutPatient";
    }
};

// Inpatient bill
class InPatientBill : public Bill {
private:
    int days;
    double perDay;
    double surgery;

public:
    InPatientBill(const string& p, int d, double pd, double s)
        : Bill(p), days(d), perDay(pd), surgery(s) {}

    double total() const override {
        return days * perDay + surgery;
    }

    string type() const override {
        return "InPatient";
    }
};

// Day-care surgery bill
class DayCareBill : public Bill {
private:
    double packageCharge;

public:
    DayCareBill(const string& p, double pc)
        : Bill(p), packageCharge(pc) {}

    double total() const override {
        return packageCharge;
    }

    string type() const override {
        return "DayCare";
    }
};

// Emergency bill
class EmergencyBill : public Bill {
private:
    double baseCharge;
    double timeCharge;

public:
    EmergencyBill(const string& p, double b, double t)
        : Bill(p), baseCharge(b), timeCharge(t) {}

    double total() const override {
        return baseCharge + timeCharge;
    }

    string type() const override {
        return "Emergency";
    }
};

int main() {

    Bill* bills[] = {
        new OutPatientBill("Ravi", 500, 1200),
        new InPatientBill("Meena", 3, 2500, 40000),
        new DayCareBill("Arjun", 25000),
        new EmergencyBill("Priya", 5000, 3500)
    };

    double grandTotal = 0;

    cout << "HOSPITAL BILL DETAILS\n";
    cout << "---------------------\n";

    for (Bill* b : bills) {
        b->print();
        grandTotal += b->total();
    }

    cout << "---------------------\n";
    cout << "Grand Total: " << grandTotal << '\n';

    for (Bill* b : bills) {
        delete b;
    }

    return 0;
}