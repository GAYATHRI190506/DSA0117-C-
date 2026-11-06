#include <iostream>
using namespace std;

int main()
{
    cout << "METRO SMART-CARD SYSTEM - FINAL RECOMMENDATION" << endl;
    cout << "===============================================" << endl;

    cout << "\nRecommended Design Decisions" << endl;
    cout << "----------------------------" << endl;

    cout << "1. Use Object-Oriented Programming (OOP)." << endl;
    cout << "2. Use classes to represent SmartCard, Passenger and Journey." << endl;
    cout << "3. Use enum class for metro zones." << endl;
    cout << "4. Store money in integer paise to avoid floating-point errors." << endl;
    cout << "5. Use long long for balance and fare calculations." << endl;
    cout << "6. Keep fare calculation and validation in separate functions." << endl;
    cout << "7. Validate zone, balance and travel time before processing." << endl;
    cout << "8. Apply concessions and peak-hour rules consistently." << endl;
    cout << "9. Maintain at least Rs 50 balance after every journey." << endl;
    cout << "10. Use test cases to validate normal and boundary conditions." << endl;

    cout << "\nComplexity Recommendation" << endl;
    cout << "-------------------------" << endl;
    cout << "Time Complexity  : O(1) per journey" << endl;
    cout << "Space Complexity : O(1) per smart card" << endl;

    cout << "\nFinal Recommendation" << endl;
    cout << "--------------------" << endl;
    cout << "The Object-Oriented design is recommended because it provides" << endl;
    cout << "better encapsulation, maintainability, validation and scalability." << endl;
    cout << "The final fare system should use integer paise and long long" << endl;
    cout << "for reliable monetary calculations." << endl;

    cout << "\nResult: RECOMMENDED DESIGN - OOP BASED METRO FARE SYSTEM" << endl;

    return 0;
}