
#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace chrono;

class Bill {
public:
    virtual double total() const = 0;
    virtual ~Bill() = default;
};

class OutPatient : public Bill {
    double amount;
public:
    OutPatient(double a) : amount(a) {}
    double total() const override { return amount + 200; }
};

class InPatient : public Bill {
    double amount;
public:
    InPatient(double a) : amount(a) {}
    double total() const override { return amount + 1000; }
};

struct SwitchBill {
    int type;
    double amount;

    double total() const {
        switch (type) {
            case 1: return amount + 200;
            case 2: return amount + 1000;
            default: return 0;
        }
    }
};

volatile double resultSink = 0;

int main() {
    const int sizes[] = {1000, 1000000, 10000000};

    cout << fixed << setprecision(3);
    cout << "VIRTUAL vs SWITCH BENCHMARK\n";
    cout << "---------------------------\n";

    for (int n : sizes) {
        vector<Bill*> virtualBills;
        vector<SwitchBill> switchBills;

        virtualBills.reserve(n);
        switchBills.reserve(n);

        for (int i = 0; i < n; i++) {
            double amount = 1000 + (i % 500);

            if (i % 2 == 0)
                virtualBills.push_back(new OutPatient(amount));
            else
                virtualBills.push_back(new InPatient(amount));

            switchBills.push_back({i % 2 == 0 ? 1 : 2, amount});
        }

        double virtualTotal = 0;
        auto start1 = high_resolution_clock::now();

        for (const Bill* b : virtualBills)
            virtualTotal += b->total();

        auto end1 = high_resolution_clock::now();

        double switchTotal = 0;
        auto start2 = high_resolution_clock::now();

        for (const auto& b : switchBills)
            switchTotal += b.total();

        auto end2 = high_resolution_clock::now();

        auto virtualTime =
            duration_cast<microseconds>(end1 - start1).count();

        auto switchTime =
            duration_cast<microseconds>(end2 - start2).count();

        resultSink = virtualTotal + switchTotal;

        cout << "\nBills: " << n << '\n';
        cout << "Virtual total: " << virtualTotal << '\n';
        cout << "Switch total : " << switchTotal << '\n';
        cout << "Virtual time : " << virtualTime << " microseconds\n";
        cout << "Switch time  : " << switchTime << " microseconds\n";

        for (Bill* b : virtualBills)
            delete b;
    }

    return 0;
}
