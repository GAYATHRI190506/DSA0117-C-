
#include <iostream>
#include <exception>
#include <string>
using namespace std;

// Custom exception classes
class InvalidBillException : public exception {
public:
    const char* what() const noexcept override {
        return "Bill amount cannot be negative.";
    }
};

class InvalidPatientException : public exception {
public:
    const char* what() const noexcept override {
        return "Patient name cannot be empty.";
    }
};

class PaymentException : public exception {
public:
    const char* what() const noexcept override {
        return "Insufficient payment amount.";
    }
};

class InsuranceLimitException : public exception {
public:
    const char* what() const noexcept override {
        return "Insurance claim exceeds the allowed limit.";
    }
};

class InvalidPayerException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid payer selected.";
    }
};

// noexcept function
double getTaxRate() noexcept {
    return 0.05;
}

// Validation functions
void validateBill(double amount) {
    if (amount < 0) {
        throw InvalidBillException();
    }
}

void validatePatient(const string& name) {
    if (name.empty()) {
        throw InvalidPatientException();
    }
}

void validatePayment(double paid, double total) {
    if (paid < total) {
        throw PaymentException();
    }
}

void validateInsurance(double claim, double limit) {
    if (claim > limit) {
        throw InsuranceLimitException();
    }
}

void validatePayer(const string& payer) {
    if (payer != "SelfPay" &&
        payer != "Insurance" &&
        payer != "GovernmentScheme") {
        throw InvalidPayerException();
    }
}

int main() {
    cout << "HOSPITAL BILL EXCEPTION DEMO" << endl;
    cout << "----------------------------" << endl;

    try {
        validateBill(1700);
        validatePatient("Ravi");
        validatePayment(2000, 1700);
        validateInsurance(1500, 2000);
        validatePayer("Insurance");

        cout << "Bill validation: Successful" << endl;
        cout << "Patient validation: Successful" << endl;
        cout << "Payment validation: Successful" << endl;
        cout << "Insurance validation: Successful" << endl;
        cout << "Payer validation: Successful" << endl;

        cout << "Tax Rate: "
             << getTaxRate() * 100 << "%" << endl;

        // Demonstrate an invalid bill
        validateBill(-500);
    }
    catch (const exception& e) {
        cout << "Exception Caught: " << e.what() << endl;
    }

    cout << "Program completed safely." << endl;

    return 0;
}
