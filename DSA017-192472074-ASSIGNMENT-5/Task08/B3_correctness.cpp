
#include <iostream>
#include <vector>
#include <iomanip>

class Bill {
public:
    virtual double total() const = 0;
    virtual ~Bill() = default;
};

class OutPatient : public Bill {
    double consultation, tests;

public:
    OutPatient(double c, double t) : consultation(c), tests(t) {}

    double total() const override {
        return consultation + tests;
    }
};

class InPatient : public Bill {
    int days;
    double perDay, surgery;

public:
    InPatient(int d, double rate, double s)
        : days(d), perDay(rate), surgery(s) {}

    double total() const override {
        return days * perDay + surgery;
    }
};

struct SwitchBill {
    int type;
    int days;
    double first;
    double second;
};

double switchTotal(const SwitchBill& b) {
    switch (b.type) {
        case 1: return b.first + b.second;
        case 2: return b.days * b.first + b.second;
        default: return 0;
    }
}

int main() {
    std::vector<Bill*> virtualBills;
    std::vector<SwitchBill> switchBills;

    for (int i = 0; i < 10; ++i) {
        if (i % 2 == 0) {
            double consultation = 500 + i * 10;
            double tests = 1200 + i * 5;

            virtualBills.push_back(
                new OutPatient(consultation, tests));

            switchBills.push_back(
                {1, 0, consultation, tests});
        } else {
            int days = 2 + i;
            double rate = 2500;
            double surgery = 10000;

            virtualBills.push_back(
                new InPatient(days, rate, surgery));

            switchBills.push_back(
                {2, days, rate, surgery});
        }
    }

    double virtualSum = 0;
    double switchSum = 0;

    for (const Bill* b : virtualBills)
        virtualSum += b->total();

    for (const SwitchBill& b : switchBills)
        switchSum += switchTotal(b);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Virtual function total: " << virtualSum << '\n';
    std::cout << "Switch statement total: " << switchSum << '\n';

    if (virtualSum == switchSum)
        std::cout << "RESULT: Both methods agree\n";
    else
        std::cout << "RESULT: Totals differ\n";

    for (Bill* b : virtualBills)
        delete b;

    return 0;
}
