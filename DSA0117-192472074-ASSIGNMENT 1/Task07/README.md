# Task 07 – Procedural vs Object-Oriented SmartCard Design

## Assignment
DSA01 – C++ Assignment 1

## Task
Task 7 – Compare Procedural and Object-Oriented SmartCard Design

## Objective
To compare procedural programming and object-oriented programming approaches for implementing a SmartCard system.

## Procedural Approach

The procedural implementation uses global variables and free functions to store and process SmartCard information.

### Main Features
- Global card balance and fare variables
- Free functions for fare validation and display
- Direct access to global data
- Simple implementation for a small system

## Object-Oriented Approach

The object-oriented implementation uses a `SmartCard` class.

### Main Features
- Private data members for balance and fare
- Member functions for SmartCard operations
- Encapsulation of data and behaviour
- Better organization for a larger system

## Comparison

| Procedural Approach | Object-Oriented Approach |
|---|---|
| Uses global variables | Uses private data members |
| Uses free functions | Uses member functions |
| Less data protection | Better data protection |
| Data and behaviour are separate | Data and behaviour are combined |
| Suitable for simple programs | Suitable for larger systems |
| Less extensible | More extensible |

## Execution

### Procedural Compile Command

g++ -std=c++17 -Wall -Wextra procedural.cpp -o procedural

### Procedural Run Command

.\procedural.exe

### OOP Compile Command

g++ -std=c++17 -Wall -Wextra oop.cpp -o oop

### OOP Run Command

.\oop.exe

## Result

Both procedural and object-oriented SmartCard implementations were designed for the metro fare system.

The procedural version uses global variables and free functions, whereas the object-oriented version uses a `SmartCard` class with private data members and member functions.

The OOP approach provides better encapsulation and keeps related data and behaviour together. Therefore, the object-oriented approach is more suitable for extending the SmartCard system.

## Output

Both implementations successfully displayed the SmartCard balance, fare, and journey status.

## Evidence

- Task07_Procedural_Output.png
- Task07_OOP_Output.png