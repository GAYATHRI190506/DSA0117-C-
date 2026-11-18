
#include <iostream>
#include <vector>
using namespace std;

class Account {
public:
    Account() {
        cout << "Account constructor" << endl;
    }

    virtual ~Account() {
        cout << "Account destructor" << endl;
    }

    double rate() const {
        return 3.5;
    }

    virtual double vrate() const {
        return 3.5;
    }
};

class SeniorAccount : public Account {
public:
    SeniorAccount() {
        cout << "SeniorAccount constructor" << endl;
    }

    ~SeniorAccount() override {
        cout << "SeniorAccount destructor" << endl;
    }

    double rate() const {
        return 4.0;
    }

    double vrate() const override {
        return 4.0;
    }
};

int main() {
    cout << "--- Creating SeniorAccount ---" << endl;
    SeniorAccount senior;

    cout << "\n--- Base Pointer ---" << endl;
    Account* ptr = &senior;

    cout << "Non-virtual rate: " << ptr->rate() << endl;
    cout << "Virtual rate: " << ptr->vrate() << endl;

    cout << "\n--- Object Slicing ---" << endl;
    Account copy = senior;

    cout << "Copied object virtual rate: "
         << copy.vrate() << endl;

    cout << "\n--- Polymorphic Vector ---" << endl;

    vector<Account*> accounts;
    accounts.push_back(&senior);

    for (Account* a : accounts) {
        cout << "Account rate: " << a->vrate() << endl;
    }

    cout << "\n--- Program Ending ---" << endl;

    return 0;
}
