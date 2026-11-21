
#include <iostream>
using namespace std;

class Bill {
public:
    double total() const {
        return 0;
    }
};

class OutPatient : public Bill {
public:
    double total() const {
        return 1700;
    }
};

int main() {
    OutPatient op;

    Bill* b = &op;

    cout << "Using derived object: " << op.total() << '\n';
    cout << "Using base pointer: " << b->total() << '\n';

    return 0;
}
