#include <iostream>
#include <string>

class Staff {
protected:
    std::string name;
    int id;
    double basic;

public:
    Staff(const std::string& n, int i, double b)
        : name(n), id(i), basic(b) {}

    virtual double pay() const = 0;

    virtual ~Staff() = default;
};

class Professor : public Staff {
    double research;

public:
    Professor(const std::string& n, int i, double b, double r)
        : Staff(n, i, b), research(r) {}

    double pay() const override {
        return basic + basic * 0.42 + research;
    }
};

class LabAssistant : public Staff {
public:
    LabAssistant(const std::string& n, int i, double b)
        : Staff(n, i, b) {}

    double pay() const override {
        return basic + basic * 0.42;
    }
};

class GuestFaculty : public Staff {
    double hours;
    double rate;

public:
    GuestFaculty(const std::string& n, int i, double h, double r)
        : Staff(n, i, 0), hours(h), rate(r) {}

    double pay() const override {
        return hours * rate;
    }
};

int main() {
    Professor p("Ravi", 101, 50000, 10000);
    LabAssistant l("Anita", 102, 30000);
    GuestFaculty g("Kiran", 103, 40, 1000);

    Staff* staff[] = {&p, &l, &g};

    for (Staff* s : staff) {
        std::cout << s->pay() << '\n';
    }

    return 0;
}