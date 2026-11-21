
#include <iostream>
using namespace std;

class Bill {
public:
    ~Bill() {
        cout << "Bill destructor\n";
    }
};

class OutPatient : public Bill {
public:
    ~OutPatient() {
        cout << "OutPatient destructor\n";
    }
};

int main() {
    Bill* b = new OutPatient();

    delete b;

    return 0;
}
