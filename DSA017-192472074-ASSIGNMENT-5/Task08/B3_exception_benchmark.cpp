
#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <stdexcept>
using namespace std;
using namespace chrono;

const int CLAIM_COUNT = 1000000;
volatile long long resultSink = 0;

int processWithReturnCode(int amount, int limit) {
    if (amount < 0 || amount > limit)
        return -1;

    return amount;
}

int processWithException(int amount, int limit) {
    if (amount < 0 || amount > limit)
        throw runtime_error("Invalid claim");

    return amount;
}

void runTest(int invalidPercent) {
    vector<int> claims(CLAIM_COUNT, 500);
    const int limit = 1000;

    int invalidCount = CLAIM_COUNT * invalidPercent / 100;

    for (int i = 0; i < invalidCount; i++)
        claims[i] = 1500;

    long long returnTotal = 0;
    int returnErrors = 0;

    auto start1 = high_resolution_clock::now();

    for (int amount : claims) {
        int result = processWithReturnCode(amount, limit);

        if (result == -1)
            returnErrors++;
        else
            returnTotal += result;
    }

    auto end1 = high_resolution_clock::now();

    long long exceptionTotal = 0;
    int exceptionErrors = 0;

    auto start2 = high_resolution_clock::now();

    for (int amount : claims) {
        try {
            exceptionTotal += processWithException(amount, limit);
        }
        catch (const runtime_error&) {
            exceptionErrors++;
        }
    }

    auto end2 = high_resolution_clock::now();

    resultSink = returnTotal + exceptionTotal;

    auto returnTime =
        duration_cast<milliseconds>(end1 - start1).count();

    auto exceptionTime =
        duration_cast<milliseconds>(end2 - start2).count();

    cout << "\nInvalid claims: " << invalidPercent << "%\n";
    cout << "Return code errors: " << returnErrors << '\n';
    cout << "Exception errors  : " << exceptionErrors << '\n';
    cout << "Return code time  : " << returnTime << " ms\n";
    cout << "Exception time    : " << exceptionTime << " ms\n";
}

int main() {
    cout << "RETURN CODE vs EXCEPTION BENCHMARK\n";
    cout << "Claims processed: " << CLAIM_COUNT << '\n';

    runTest(0);
    runTest(1);
    runTest(50);

    return 0;
}
