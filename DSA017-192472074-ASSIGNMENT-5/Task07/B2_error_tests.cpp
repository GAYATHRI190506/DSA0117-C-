
#include <iostream>
#include <stdexcept>
#include <string>
#include <limits>
#include <new>
#include <memory>
using namespace std;

// Resource tracker to demonstrate destructor execution
class ResourceTracker {
    string name;

public:
    explicit ResourceTracker(string n) : name(n) {
        cout << name << " created\n";
    }

    ~ResourceTracker() {
        cout << name << " destroyed\n";
    }
};

// Test 1: Negative charges
void checkCharge(double charge) {
    if (charge < 0) {
        throw invalid_argument("negative charge");
    }

    cout << "Charge accepted: " << charge << '\n';
}

// Test 2: Claim above insurance cover
void checkClaim(double billed, double cover) {
    if (billed > cover) {
        throw runtime_error("claim exceeds insurance cover");
    }

    cout << "Claim accepted\n";
}

// Test 3: Unknown package code
void checkPackage(int packageCode) {
    if (packageCode != 101 && packageCode != 102) {
        throw runtime_error("unknown package code");
    }

    cout << "Package accepted\n";
}

// Test 4: Invalid numeric input
void checkNumber(const string& input) {
    try {
        size_t position = 0;
        double value = stod(input, &position);

        if (position != input.size()) {
            throw invalid_argument("invalid numeric input");
        }

        cout << "Converted number: " << value << '\n';
    }
    catch (const invalid_argument&) {
        cout << "Invalid number entered\n";
        throw;
    }
}

// Test 5: Memory allocation failure
void forceAllocationFailure() {
    cout << "Requesting impossible allocation...\n";

    // Runtime size prevents GCC from rejecting it
    // as a compile-time constant expression.
    volatile size_t requested =
        numeric_limits<size_t>::max();

    unique_ptr<char[]> memory(new char[requested]);

    cout << "Allocation succeeded unexpectedly\n";
}

// Common function to execute and catch errors
void runTest(const string& testName, void (*test)()) {
    cout << "\n--- " << testName << " ---\n";

    try {
        ResourceTracker resource(testName);

        test();

        cout << "Test completed\n";
    }
    catch (const bad_alloc& e) {
        cout << "Memory error caught: " << e.what() << '\n';
    }
    catch (const exception& e) {
        cout << "Exception caught: " << e.what() << '\n';
    }
    catch (...) {
        cout << "Unknown exception caught\n";
    }

    cout << "Program continues\n";
}

// Individual test functions
void testNegativeCharge() {
    checkCharge(-500);
}

void testClaimAboveCover() {
    checkClaim(60000, 50000);
}

void testUnknownPackage() {
    checkPackage(999);
}

void testInvalidNumber() {
    checkNumber("abc");
}

void testAllocationFailure() {
    forceAllocationFailure();
}

// Main function
int main() {
    cout << "HOSPITAL BILLING - ERROR TESTS\n";

    runTest("Negative charge", testNegativeCharge);

    runTest("Claim above cover", testClaimAboveCover);

    runTest("Unknown package", testUnknownPackage);

    runTest("Invalid numeric input", testInvalidNumber);

    runTest("Allocation failure", testAllocationFailure);

    cout << "\nAll error tests finished safely.\n";

    return 0;
}
