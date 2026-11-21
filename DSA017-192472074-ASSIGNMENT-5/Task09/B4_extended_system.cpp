
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <iomanip>
using namespace std;

// Base bill class
class Bill {
protected:
    string patient;
public:
    Bill(string p) : patient(p) {}

    virtual double total() const = 0;

    virtual string type() const = 0;

    string getPatient() const {
        return patient;
    }

    virtual ~Bill() = default;
};

// Existing bill types
class OutPatient : public Bill {
    double consultation, medicine;
public:
    OutPatient(string p, double c, double m)
        : Bill(p), consultation(c), medicine(m) {}

    double total() const override {
        return consultation + medicine;
    }

    string type() const override {
        return "OutPatient";
    }
};

class InPatient : public Bill {
    double room, treatment;
public:
    InPatient(string p, double r, double t)
        : Bill(p), room(r), treatment(t) {}

    double total() const override {
        return room + treatment;
    }

    string type() const override {
        return "InPatient";
    }
};

// New bill type 1
class SurgeryBill : public Bill {
    double operation, equipment;
public:
    SurgeryBill(string p, double o, double e)
        : Bill(p), operation(o), equipment(e) {}

    double total() const override {
        return operation + equipment;
    }

    string type() const override {
        return "Surgery";
    }
};

// New bill type 2
class LaboratoryBill : public Bill {
    double test, sample;
public:
    LaboratoryBill(string p, double t, double s)
        : Bill(p), test(t), sample(s) {}

    double total() const override {
        return test + sample;
    }

    string type() const override {
        return "Laboratory";
    }
};

// Base payer
class Payer {
public:
    virtual double coverage(double amount) const = 0;
    virtual string name() const = 0;
    virtual ~Payer() = default;
};

// Existing payers
class SelfPay : public Payer {
public:
    double coverage(double amount) const override {
        return amount;
    }

    string name() const override {
        return "SelfPay";
    }
};

class Insurance : public Payer {
public:
    double coverage(double amount) const override {
        return amount * 0.80;
    }

    string name() const override {
        return "Insurance";
    }
};

class GovernmentScheme : public Payer {
public:
    double coverage(double amount) const override {
        return amount * 0.90;
    }

    string name() const override {
        return "GovernmentScheme";
    }
};

// New payer
class SeniorCitizenScheme : public Payer {
public:
    double coverage(double amount) const override {
        return amount * 0.95;
    }

    string name() const override {
        return "SeniorCitizenScheme";
    }
};

int main() {
    vector<unique_ptr<Bill>> bills;

    bills.push_back(make_unique<OutPatient>("Ravi", 1000, 700));
    bills.push_back(make_unique<InPatient>("Meena", 25000, 22500));
    bills.push_back(make_unique<SurgeryBill>("Arjun", 50000, 15000));
    bills.push_back(make_unique<LaboratoryBill>("Priya", 3000, 1200));

    vector<unique_ptr<Payer>> payers;

    payers.push_back(make_unique<SelfPay>());
    payers.push_back(make_unique<Insurance>());
    payers.push_back(make_unique<GovernmentScheme>());
    payers.push_back(make_unique<SeniorCitizenScheme>());

    cout << fixed << setprecision(2);
    cout << "HOSPITAL BILLING - EXTENDED SYSTEM\n";
    cout << "==================================\n";

    for (const auto& bill : bills) {
        double amount = bill->total();

        cout << "\nBill Type: " << bill->type() << '\n';
        cout << "Patient  : " << bill->getPatient() << '\n';
        cout << "Total    : Rs. " << amount << '\n';

        for (const auto& payer : payers) {
            cout << payer->name() << " covers: Rs. "
                 << payer->coverage(amount) << '\n';
        }
    }

    return 0;
}
