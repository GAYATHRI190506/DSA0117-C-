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

    Prescription(const Prescription& other)
        : n(other.n), medicines(new std::string[other.n])
    {
        for (int i = 0; i < n; ++i)
        {
            medicines[i] = other.medicines[i];
        }
    }

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

    p = p;

    std::cout << "After self-assignment: "
              << p.get(0) << " "
              << p.get(1) << '\n';

    return 0;
}