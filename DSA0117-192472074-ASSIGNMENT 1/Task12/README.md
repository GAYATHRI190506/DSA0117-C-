# Task 12 – Design Challenge

## Objective

To extend the Metro Smart-Card fare system with an Airport zone, weekend discount and monthly pass functionality.

## New Requirements

- Airport zone fare: Rs 60
- Weekend discount: 10%
- Weekend discount and peak surcharge must not be combined
- Monthly pass provides unlimited journeys in two selected zones

## Design Decision

The existing OOP design should be **modified** rather than completely redesigned.

The original design provides a good foundation through classes, enumerations and separate fare-processing logic. The new requirements can be added by extending the existing design.

## Implementation

### Airport Zone

A fourth zone named Airport was added with a base fare of Rs 60.

### Weekend Discount

A 10% weekend discount is applied.

### Peak and Weekend Rule

Weekend discount and peak surcharge are mutually exclusive.

If the journey is on a weekend, the 10% discount is applied instead of the 20% peak surcharge.

### Monthly Pass

A `MonthlyPass` class stores two selected zones and checks whether a journey belongs to either covered zone.

## Complexity

- Fare calculation: O(1)
- Monthly pass zone checking: O(1)
- Space complexity: O(1)

## Compile Command

```text
g++ -std=c++17 -Wall -Wextra task12.cpp -o task12
```

## Run Command

```text
.\task12.exe
```

## Result

The design challenge was successfully implemented. The existing OOP design was modified to support the Airport zone, weekend discount and monthly pass while keeping the system structured and maintainable.

