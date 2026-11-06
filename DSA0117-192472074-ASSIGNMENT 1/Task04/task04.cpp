#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << "Implicit Type Conversion Demonstration" << endl;
    cout << "======================================" << endl;

    // 1. int to double
    int intValue = 25;
    double intToDouble = intValue;

    cout << "\n1. int to double" << endl;
    cout << "int value        : " << intValue << endl;
    cout << "double value     : " << intToDouble << endl;

    // 2. double to int
    double doubleValue = 25.75;
    int doubleToInt = doubleValue;

    cout << "\n2. double to int" << endl;
    cout << "double value     : " << doubleValue << endl;
    cout << "int value        : " << doubleToInt << endl;

    // 3. char to int
    char character = 'A';
    int charToInt = character;

    cout << "\n3. char to int" << endl;
    cout << "char value       : " << character << endl;
    cout << "ASCII value      : " << charToInt << endl;

    // 4. bool to int
    bool booleanValue = true;
    int boolToInt = booleanValue;

    cout << "\n4. bool to int" << endl;
    cout << "bool value       : " << booleanValue << endl;
    cout << "int value        : " << boolToInt << endl;

    // 5. Mixed arithmetic expression
    int a = 10;
    double b = 2.5;

    double result = a + b;

    cout << "\n5. Mixed arithmetic expression" << endl;
    cout << "int value        : " << a << endl;
    cout << "double value     : " << b << endl;
    cout << "a + b            : " << result << endl;

    // 6. Character arithmetic
    char letter = 'B';
    int number = 5;

    int characterResult = letter + number;

    cout << "\n6. Character arithmetic" << endl;
    cout << "character        : " << letter << endl;
    cout << "ASCII value      : " << static_cast<int>(letter) << endl;
    cout << "number           : " << number << endl;
    cout << "character + 5    : " << characterResult << endl;

    // 7. Boolean arithmetic
    bool first = true;
    bool second = false;

    int booleanResult = first + second;

    cout << "\n7. Boolean arithmetic" << endl;
    cout << "true + false     : " << booleanResult << endl;

    // 8. Mixed expression
    int x = 20;
    double y = 3.5;
    char z = 'C';

    double mixedResult = x + y + z;

    cout << "\n8. Mixed expression" << endl;
    cout << "x                : " << x << endl;
    cout << "y                : " << y << endl;
    cout << "z                : " << z << endl;
    cout << "x + y + z        : " << mixedResult << endl;

    // 9. Explicit comparison
    double original = 19.99;
    int converted = original;

    cout << "\n9. Narrowing conversion" << endl;
    cout << fixed << setprecision(2);
    cout << "Original double   : " << original << endl;
    cout << "Converted int     : " << converted << endl;

    // 10. Final summary
    cout << "\nConversion Summary" << endl;
    cout << "==================" << endl;
    cout << "int -> double : automatic promotion" << endl;
    cout << "double -> int : fractional part removed" << endl;
    cout << "char -> int   : character converted to ASCII value" << endl;
    cout << "bool -> int   : true becomes 1, false becomes 0" << endl;
    cout << "Mixed types   : smaller type is promoted when required" << endl;

    return 0;
}