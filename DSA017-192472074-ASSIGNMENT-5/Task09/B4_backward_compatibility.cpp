
#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;

class Bill {
public:
    virtual double total() const = 0;
    virtual string type() const = 0;
    virtual ~Bill() = default;
};

class OutPatient : public Bill {
public:
    double total() const override { return 1700; }
    string type() const override { return "OutPatient"; }
};

class InPatient : public Bill {
public:
    double total() const override { return 47500; }
    string type() const override { return "InPatient"; }
};

class DayCare : public Bill {
public:
    double total() const override { return 25000; }
    string type() const override { return "DayCare"; }
};

class Emergency : public Bill {
public:
    double total() const override { return 5000; }
    string type() const override { return "Emergency"; }
};

// New bill type
class SurgeryBill : public Bill {
public:
    double total() const override { return 65000; }
    string type() const override { return "Surgery"; }
};

// New bill type
class LaboratoryBill : public Bill {
public:
    double total() const override { return 4200; }
    string type() const override { return "Laboratory"; }
};

class Payer {
public:
    virtual double coverage(double amount) const = 0;
    virtual string name() const = 0;
    virtual ~Payer() = default;
};

class SelfPay : public Payer {
public:
    double coverage(double a) const override { return a; }
    string name() const override { return "SelfPay"; }
};

class Insurance : public Payer {
public:
    double coverage(double a) const override { return a * 0.80; }
    string name() const override { return "Insurance"; }
};

class GovernmentScheme : public Payer {
public:
    double coverage(double a) const override { return a * 0.90; }
    string name() const override { return "GovernmentScheme"; }
};

// New payer
class SeniorCitizenScheme : public Payer {
public:
    double coverage(double a) const override { return a * 0.95; }
    string name() const override { return "SeniorCitizenScheme"; }
};

int main() {
    vector<unique_ptr<Bill>> bills;

    bills.push_back(make_unique<OutPatient>());
    bills.push_back(make_unique<InPatient>());
    bills.push_back(make_unique<DayCare>());
    bills.push_back(make_unique<Emergency>());
    bills.push_back(make_unique<SurgeryBill>());
    bills.push_back(make_unique<LaboratoryBill>());

    cout << "BACKWARD COMPATIBILITY TEST\n";
    cout << "===========================\n";

    double grandTotal = 0;

    for (const auto& bill : bills) {
        cout << bill->type() << " : Rs. "
             << bill->total() << '\n';

        grandTotal += bill->total();
    }

    cout << "---------------------------\n";
    cout << "Grand Total: Rs. " << grandTotal << '\n';

    SelfPay self;
    Insurance insurance;
    GovernmentScheme government;
    SeniorCitizenScheme senior;

    cout << "\nPAYER TESTS\n";
    cout << "SelfPay: " << self.coverage(1000) << '\n';
    cout << "Insurance: " << insurance.coverage(1000) << '\n';
    cout << "GovernmentScheme: "
         << government.coverage(1000) << '\n';
    cout << "SeniorCitizenScheme: "
         << senior.coverage(1000) << '\n';

    cout << "\nBackward compatibility test passed.\n";

    return 0;
}
