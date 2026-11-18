#include <iostream>
#include <string>
using namespace std;

class Staff {
    string name;
    int type;
    double basic, research, hours, rate;

public:
    Staff(string n, int t, double b, double r, double h, double rt)
        : name(n), type(t), basic(b), research(r), hours(h), rate(rt) {}

    double pay() const {
        switch (type) {
            case 1:
                return basic + basic * 0.42 + research;
            case 2:
                return basic + basic * 0.42;
            case 3:
                return hours * rate;
            default:
                return 0;
        }
    }
};

int main() {
    Staff p("Ravi", 1, 50000, 10000, 0, 0);
    Staff l("Anita", 2, 30000, 0, 0, 0);
    Staff g("Kiran", 3, 0, 0, 40, 1000);

    cout << p.pay() << '\n';
    cout << l.pay() << '\n';
    cout << g.pay() << '\n';

    return 0;
}