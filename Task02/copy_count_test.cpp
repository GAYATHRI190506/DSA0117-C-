#include <iostream>
#include <string>

class Prescription
{
    int n;
    std::string* medicines;

public:
    static int copyCount;

    explicit Prescription(int count)
        : n(count), medicines(new std::string[count])
    {
    }

    Prescription(const Prescription& other)
        : n(other.n), medicines(new std::string[other.n])
    {
        ++copyCount;

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

int Prescription::copyCount = 0;

void byValue(Prescription p)
{
    std::cout << "Inside byValue()\n";
}

void byReference(const Prescription& p)
{
    std::cout << "Inside byReference()\n";
}

int main()
{
    Prescription p(2);

    p.set(0, "Paracetamol");
    p.set(1, "ORS");

    std::cout << "Initial copy count: "
              << Prescription::copyCount << '\n';

    byValue(p);

    std::cout << "After byValue(): "
              << Prescription::copyCount << '\n';

    byReference(p);

    std::cout << "After byReference(): "
              << Prescription::copyCount << '\n';

    Prescription q = p;

    std::cout << "After explicit copy: "
              << Prescription::copyCount << '\n';

    return 0;
}