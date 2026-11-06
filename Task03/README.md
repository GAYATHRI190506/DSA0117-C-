# Task 03 – Choose Data Types and Check Type Compatibility

## Assignment
DSA01 – C++ Assignment 1

## Task
Task 3 – Choose Data Types and Check Type Compatibility

## Objective
To select suitable C++ data types for the Metro Smart-Card Fare System and examine their size, range, compatibility and behaviour.

## Concepts Covered
- bool
- char
- int
- long long
- unsigned int
- float
- double
- auto
- sizeof()
- <climits>
- Integer paise representation
- Type compatibility
- Integer overflow
- Floating-point precision

## Program
The program demonstrates the sizes of different C++ data types, their ranges where applicable, and the use of integer paise for accurate money calculations.

## Alternative Concept
The task compares storing money as integer paise using `long long` with storing money as `double` rupees.

## Complexity
Individual arithmetic operations and type-size checks take O(1) time and O(1) additional space.

## Result
The appropriate data types for the Metro Smart-Card Fare System are identified and tested. Integer paise is preferred for monetary values because it avoids floating-point rounding problems.

## Execution

### Compile Command

g++ -std=c++17 -Wall -Wextra task03.cpp -o task03

### Run Command

.\task03

### Result

The program successfully demonstrated C++ data types, memory sizes, data type ranges, type compatibility, integer paise representation, and floating-point precision.

The program showed that long long is more suitable for storing large monetary values in paise because the total paise for 3 million journeys can exceed the range of a signed int.

Integer paise representation is preferred for fare calculations because it avoids floating-point rounding problems.


