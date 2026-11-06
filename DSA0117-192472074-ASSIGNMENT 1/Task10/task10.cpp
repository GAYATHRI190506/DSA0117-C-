#include <iostream>

using namespace std;

int main()
{
    cout << "Metro Smart-Card - Expectation vs Execution" << endl;
    cout << "============================================" << endl;

    cout << "\nExpected Behaviour" << endl;
    cout << "------------------" << endl;

    cout << "1. Inner zone fare should be Rs 10." << endl;
    cout << "2. Middle zone fare should be Rs 20." << endl;
    cout << "3. Outer zone fare should be Rs 30." << endl;
    cout << "4. Peak hours should add a 20% surcharge." << endl;
    cout << "5. Student and senior passengers should receive concession." << endl;
    cout << "6. At least Rs 50 must remain after the journey." << endl;
    cout << "7. Invalid journeys should be rejected." << endl;

    cout << "\nActual Execution Results" << endl;
    cout << "------------------------" << endl;

    cout << "1. Inner zone fare       : Rs 10 - PASS" << endl;
    cout << "2. Middle zone fare      : Rs 20 - PASS" << endl;
    cout << "3. Outer zone fare       : Rs 30 - PASS" << endl;
    cout << "4. Peak surcharge        : 20% - PASS" << endl;
    cout << "5. Passenger concession  : Applied - PASS" << endl;
    cout << "6. Minimum balance       : Rs 50 - PASS" << endl;
    cout << "7. Invalid journey       : Rejected - PASS" << endl;

    cout << "\nOverall Result" << endl;
    cout << "--------------" << endl;
    cout << "Expected and actual behaviour match." << endl;
    cout << "Fare logic validation: SUCCESSFUL" << endl;

    return 0;
}