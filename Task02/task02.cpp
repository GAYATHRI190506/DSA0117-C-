#include <iostream>
#include <string>

class Prescription
{
    int n;
    std::string* medicines; // dynamically allocated array

public:
    explicit Prescription(int count)
        : n(count), medicines(new std::string[count])
    {
    }

    // TODO 1: Copy constructor - deep copy
    Prescription(const Prescription& other)
        : n(other.n), medicines(new std::string[other.n])
    {
        for (int i = 0; i < n; ++i)
        {
            medicines[i] = other.medicines[i];
        }
    }

    // TODO 2: Copy assignment - deep copy
    Prescription& operator=(const Prescription& other)
    {
        if (this != &other)
        {
            std::string* newMedicines =
                new std::string[other.n];

            for (int i = 0; i < other.n; ++i)
            {
                newMedicines[i] = other.medicines[i];
            }

            delete[] medicines;

            n = other.n;
            medicines = newMedicines;
        }

        return *this;
    }

    // TODO 3: Destructor
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

    Prescription q = p; // copy constructor

    q.set(1, "Cetirizine");

    Prescription r(1);

    r = p; // copy assignment

    p.set(0, "Ibuprofen");

    std::cout << p.get(0) << ' '
              << p.get(1) << " | "
              << q.get(0) << ' '
              << q.get(1) << " | "
              << r.get(0) << ' '
              << r.get(1) << '\n';

    return 0;
}