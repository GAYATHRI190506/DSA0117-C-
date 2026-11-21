
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

// Abstract Bill class
class Bill {
public:
    virtual ~Bill() = default;

    virtual double total() const = 0;
    virtual string type() const = 0;
};

// OutPatient Bill
class OutPatientBill : public Bill {
    string patient;
    double consultation;
    double medicine;

public:
    OutPatientBill(string p, double c, double m)
        : patient(p), consultation(c), medicine(m) {}

    double total() const override {
        return consultation + medicine;
    }

    string type() const override {
        return "OutPatient";
    }
};

// InPatient Bill
class InPatientBill : public Bill {
    string patient;
    int days;
    double roomCharge;
    double treatment;

public:
    InPatientBill(string p, int d, double r, double t)
        : patient(p), days(d), roomCharge(r), treatment(t) {}

    double total() const override {
        return days * roomCharge + treatment;
    }

    string type() const override {
        return "InPatient";
    }
};

// Abstract Payer class
class Payer {
public:
    virtual ~Payer() = default;

    virtual double amountCovered(const Bill& bill) const = 0;
};

// SelfPay class
class SelfPay : public Payer {
public:
    double amountCovered(const Bill& bill) const override {
        return bill.total();
    }
};

// Insurance class
class Insurance : public Payer {
    double coverLimit;
    double coPaymentPercent;

public:
    Insurance(double limit, double copay)
        : coverLimit(limit), coPaymentPercent(copay) {}

    double amountCovered(const Bill& bill) const override {
        double eligible = min(bill.total(), coverLimit);
        return eligible * (1 - coPaymentPercent / 100);
    }
};

// GovernmentScheme class
class GovernmentScheme : public Payer {
    map<string, double> packageRates;

public:
    GovernmentScheme(map<string, double> rates)
        : packageRates(rates) {}

    double amountCovered(const Bill& bill) const override {
        auto it = packageRates.find(bill.type());

        if (it != packageRates.end()) {
            return min(bill.total(), it->second);
        }

        return 0;
    }
};

// New payer added without changing existing classes
class CorporateTieUp : public Payer {
public:
    double amountCovered(const Bill& bill) const override {
        return bill.total() * 0.80;
    }
};

void displayCoverage(const string& name,
                     const Payer& payer,
                     const Bill& bill) {
    cout << name << " Coverage: "
         << payer.amountCovered(bill) << endl;
}

int main() {
    OutPatientBill bill("Ravi", 500, 1200);

    SelfPay selfPay;
    Insurance insurance(2000, 20);

    GovernmentScheme government({
        {"OutPatient", 1500},
        {"InPatient", 40000}
    });

    CorporateTieUp corporate;

    cout << "PAYER COVERAGE DETAILS" << endl;
    cout << "----------------------" << endl;
    cout << "Bill Type: " << bill.type() << endl;
    cout << "Bill Total: " << bill.total() << endl;
    cout << endl;

    Payer* payers[] = {
        &selfPay,
        &insurance,
        &government,
        &corporate
    };

    string names[] = {
        "SelfPay",
        "Insurance",
        "GovernmentScheme",
        "CorporateTieUp"
    };

    for (int i = 0; i < 4; i++) {
        displayCoverage(names[i], *payers[i], bill);
    }

    return 0;
}
