#include <iostream>
#include <string>

class Prescription
{
    int n;
    std::string* medicines;

public:
    explicit Prescription(int count)
        : n(count), medicines(new std::string[count])
    {
    }

    // No copy constructor
    // No copy assignment operator

    ~Prescription()
    {
        delete[] medicines;
    }

    void set(int i, const std::string& m)
    {
        medicines[i] = m;
    }

    std::string get(int i) const
    {
        return medicines[i];
    }
};

int main()
{
    Prescription p(2);

    p.set(0, "Paracetamol");
    p.set(1, "ORS");

    Prescription q = p;   // Compiler-generated shallow copy

    q.set(1, "Cetirizine");

    std::cout << "Original: "
              << p.get(0) << " "
              << p.get(1) << '\n';

    std::cout << "Copy: "
              << q.get(0) << " "
              << q.get(1) << '\n';

    return 0;
}