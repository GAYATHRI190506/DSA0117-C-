# Task 11 – Final Recommendation

## Objective

To provide the final recommendation for the design and implementation of the Metro Smart-Card fare system.

## Recommended Design

The Object-Oriented Programming (OOP) approach is recommended because it provides better encapsulation, maintainability, validation and scalability.

## Key Recommendations

1. Use OOP classes for SmartCard, Passenger and Journey.
2. Use `enum class` for metro zones.
3. Store monetary values in integer paise.
4. Use `long long` for balance and fare calculations.
5. Separate fare calculation and validation functions.
6. Validate zone, balance and travel time.
7. Apply concessions and peak-hour rules consistently.
8. Maintain a minimum balance of Rs 50 after a journey.
9. Use test cases for normal and boundary conditions.

## Complexity

- Time Complexity: O(1) per journey
- Space Complexity: O(1) per smart card

## Compile Command

```text
g++ -std=c++17 -Wall -Wextra task11.cpp -o task11
```

## Run Command

```text
.\task11.exe
```

## Result

The OOP-based Metro Smart-Card design is recommended because it provides a structured, maintainable and scalable solution for the fare system.

## Evidence

`Task11_Output.png`