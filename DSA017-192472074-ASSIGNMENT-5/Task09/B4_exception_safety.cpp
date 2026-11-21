
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
using namespace std;

class BillingError : public exception {
    string message;

public:
    explicit BillingError(const string& msg)
        : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

class Bill {
public:
    virtual double total() const = 0;

    virtual ~Bill() {
        cout << "Bill destroyed\n";
    }
};

class SurgeryBill : public Bill {
    double amount;

public:
    explicit SurgeryBill(double a) : amount(a) {
        if (a < 0)
            throw BillingError("Negative surgery amount");
    }

    double total() const override {
        return amount;
    }

    ~SurgeryBill() override {
        cout << "SurgeryBill destroyed\n";
    }
};

void processBill(double amount) {
    unique_ptr<Bill> bill =
        make_unique<SurgeryBill>(amount);

    cout << "Bill total: Rs. " << bill->total() << '\n';

    if (amount > 50000)
        throw BillingError("Bill exceeds approval limit");

    cout << "Bill approved successfully\n";
}

int main() {
    cout << "EXCEPTION SAFETY TEST\n";
    cout << "=====================\n";

    try {
        cout << "\nTest 1: Valid bill\n";
        processBill(30000);
    }
    catch (const BillingError& e) {
        cout << "Caught: " << e.what() << '\n';
    }

    try {
        cout << "\nTest 2: Negative bill\n";
        processBill(-500);
    }
    catch (const BillingError& e) {
        cout << "Caught: " << e.what() << '\n';
    }

    try {
        cout << "\nTest 3: Bill above approval limit\n";
        processBill(75000);
    }
    catch (const BillingError& e) {
        cout << "Caught: " << e.what() << '\n';
    }

    cout << "\nAll exception tests completed.\n";
    cout << "Program continues safely.\n";

    return 0;
}
