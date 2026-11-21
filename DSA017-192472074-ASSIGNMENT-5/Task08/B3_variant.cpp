
#include <iostream>
#include <vector>
#include <variant>
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
    double total() const override {
        return amount + 200;
    }
};

class InPatient : public Bill {
    double amount;
public:
    InPatient(double a) : amount(a) {}
    double total() const override {
        return amount + 1000;
    }
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

struct VariantOutPatient {
    double amount;

    double total() const {
        return amount + 200;
    }
};

struct VariantInPatient {
    double amount;

    double total() const {
        return amount + 1000;
    }
};

using VariantBill = variant<VariantOutPatient, VariantInPatient>;

double calculateVariant(const VariantBill& bill) {
    return visit([](const auto& b) {
        return b.total();
    }, bill);
}

volatile double resultSink = 0;

int main() {
    const int N = 10000000;

    vector<Bill*> virtualBills;
    vector<SwitchBill> switchBills;
    vector<VariantBill> variantBills;

    virtualBills.reserve(N);
    switchBills.reserve(N);
    variantBills.reserve(N);

    for (int i = 0; i < N; i++) {
        double amount = 1000 + (i % 500);

        if (i % 2 == 0) {
            virtualBills.push_back(new OutPatient(amount));
            switchBills.push_back({1, amount});
            variantBills.push_back(VariantOutPatient{amount});
        }
        else {
            virtualBills.push_back(new InPatient(amount));
            switchBills.push_back({2, amount});
            variantBills.push_back(VariantInPatient{amount});
        }
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

    double variantTotal = 0;
    auto start3 = high_resolution_clock::now();

    for (const auto& b : variantBills)
        variantTotal += calculateVariant(b);

    auto end3 = high_resolution_clock::now();

    resultSink = virtualTotal + switchTotal + variantTotal;

    cout << fixed << setprecision(2);
    cout << "VIRTUAL vs SWITCH vs VARIANT\n";
    cout << "----------------------------\n";

    cout << "Bills processed: " << N << "\n\n";

    cout << "Virtual total: " << virtualTotal << '\n';
    cout << "Virtual time : "
         << duration_cast<milliseconds>(end1 - start1).count()
         << " ms\n\n";

    cout << "Switch total : " << switchTotal << '\n';
    cout << "Switch time  : "
         << duration_cast<milliseconds>(end2 - start2).count()
         << " ms\n\n";

    cout << "Variant total: " << variantTotal << '\n';
    cout << "Variant time : "
         << duration_cast<milliseconds>(end3 - start3).count()
         << " ms\n\n";

    cout << "Size of VariantBill: "
         << sizeof(VariantBill) << " bytes\n";

    cout << "\nAll totals equal: "
         << (virtualTotal == switchTotal &&
             switchTotal == variantTotal ? "YES" : "NO")
         << '\n';

    for (Bill* b : virtualBills)
        delete b;

    return 0;
}
