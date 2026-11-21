
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Bill {
protected:
    string patient;

public:
    explicit Bill(string p) : patient(p) {}
    virtual ~Bill() = default;

    virtual double total() const = 0;
    virtual string type() const = 0;

    string getPatient() const {
        return patient;
    }
};

class OutPatientBill : public Bill {
    double consultation, tests;

public:
    OutPatientBill(string p, double c, double t)
        : Bill(p), consultation(c), tests(t) {}

    double total() const override {
        return consultation + tests;
    }

    string type() const override {
        return "OutPatient";
    }
};

class InPatientBill : public Bill {
    int days;
    double perDay, surgery;

public:
    InPatientBill(string p, int d, double rate, double s)
        : Bill(p), days(d), perDay(rate), surgery(s) {}

    double total() const override {
        return days * perDay + surgery;
    }

    string type() const override {
        return "InPatient";
    }
};

class DayCareBill : public Bill {
    double packagePrice;

public:
    DayCareBill(string p, double price)
        : Bill(p), packagePrice(price) {}

    double total() const override {
        return packagePrice;
    }

    string type() const override {
        return "DayCare";
    }
};

class EmergencyBill : public Bill {
    double baseCharge, hourlyCharge;
    int hours;

public:
    EmergencyBill(string p, double base, double rate, int h)
        : Bill(p), baseCharge(base), hourlyCharge(rate), hours(h) {}

    double total() const override {
        return baseCharge + hourlyCharge * hours;
    }

    string type() const override {
        return "Emergency";
    }
};

class Payer {
public:
    virtual ~Payer() = default;
    virtual double amountCovered(const Bill& bill) const = 0;
    virtual string name() const = 0;
};

class SelfPay : public Payer {
public:
    double amountCovered(const Bill& bill) const override {
        return bill.total();
    }

    string name() const override {
        return "SelfPay";
    }
};

class Insurance : public Payer {
    double coverLimit;
    double coPaymentPercent;

public:
    Insurance(double limit, double copay)
        : coverLimit(limit), coPaymentPercent(copay) {}

    double amountCovered(const Bill& bill) const override {
        double eligible = min(bill.total(), coverLimit);
        return eligible * (1.0 - coPaymentPercent / 100.0);
    }

    string name() const override {
        return "Insurance";
    }
};

class GovernmentScheme : public Payer {
public:
    double amountCovered(const Bill& bill) const override {
        if (bill.type() == "OutPatient")
            return 1500;
        if (bill.type() == "InPatient")
            return 40000;
        if (bill.type() == "DayCare")
            return 22000;
        if (bill.type() == "Emergency")
            return 4500;

        return 0;
    }

    string name() const override {
        return "GovernmentScheme";
    }
};

int main() {
    vector<Bill*> bills = {
        new OutPatientBill("Ravi", 500, 1200),
        new InPatientBill("Meena", 3, 2500, 40000),
        new DayCareBill("Arjun", 25000),
        new EmergencyBill("Priya", 3000, 1000, 2)
    };

    SelfPay self;
    Insurance insurance(30000, 20);
    GovernmentScheme government;

    vector<Payer*> payers = {
        &self, &insurance, &government
    };

    cout << "POLYMORPHIC BILLING VALIDATION\n";
    cout << "------------------------------\n";

    for (Bill* bill : bills) {
        cout << "\nBill: " << bill->type()
             << " | Patient: " << bill->getPatient()
             << " | Total: " << bill->total() << '\n';

        for (Payer* payer : payers) {
            cout << payer->name() << " covers: "
                 << payer->amountCovered(*bill) << '\n';
        }
    }

    for (Bill* bill : bills)
        delete bill;

    return 0;
}
