#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

class Counter
{
    long long value;

public:
    Counter(long long v = 0) : value(v) {}

    Counter& operator++()
    {
        ++value;
        return *this;
    }

    Counter operator++(int)
    {
        Counter old = *this;
        ++value;
        return old;
    }

    long long getValue() const
    {
        return value;
    }
};

int main()
{
    const int N = 1000000;

    Counter prefixCounter;
    Counter postfixCounter;

    auto start1 = high_resolution_clock::now();

    for (int i = 0; i < N; ++i)
    {
        ++prefixCounter;
    }

    auto end1 = high_resolution_clock::now();

    auto start2 = high_resolution_clock::now();

    for (int i = 0; i < N; ++i)
    {
        postfixCounter++;
    }

    auto end2 = high_resolution_clock::now();

    auto prefixTime =
        duration_cast<microseconds>(end1 - start1).count();

    auto postfixTime =
        duration_cast<microseconds>(end2 - start2).count();

    cout << "INCREMENT TIMING TEST\n";
    cout << "=====================\n\n";

    cout << "Iterations: " << N << '\n';
    cout << "Prefix final value: "
         << prefixCounter.getValue() << '\n';
    cout << "Postfix final value: "
         << postfixCounter.getValue() << '\n';

    cout << "Prefix ++ time: "
         << prefixTime << " microseconds\n";

    cout << "Postfix ++ time: "
         << postfixTime << " microseconds\n";

    return 0;
}