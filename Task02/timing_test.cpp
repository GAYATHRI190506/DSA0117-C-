#include <iostream>
#include <string>
#include <chrono>

class Prescription
{
    int n;
    std::string* medicines;

public:
    explicit Prescription(int count)
        : n(count), medicines(new std::string[count])
    {
        for (int i = 0; i < n; ++i)
        {
            medicines[i] = "Medicine";
        }
    }

    // Deep copy constructor
    Prescription(const Prescription& other)
        : n(other.n), medicines(new std::string[other.n])
    {
        for (int i = 0; i < n; ++i)
        {
            medicines[i] = other.medicines[i];
        }
    }

    ~Prescription()
    {
        delete[] medicines;
    }
};

void testCopy(int count)
{
    Prescription original(count);

    auto start = std::chrono::high_resolution_clock::now();

    Prescription copy = original;

    auto end = std::chrono::high_resolution_clock::now();

    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(
            end - start
        );

    std::cout << "Medicines: " << count
              << " | Copy time: "
              << duration.count()
              << " microseconds\n";
}

int main()
{
    std::cout << "COPY CONSTRUCTOR TIMING TEST\n";
    std::cout << "============================\n\n";

    testCopy(10);
    testCopy(1000);
    testCopy(100000);

    return 0;
}