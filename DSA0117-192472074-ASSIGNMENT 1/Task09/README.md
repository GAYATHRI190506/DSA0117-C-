## Execution

### Compile Command

g++ -std=c++17 -Wall -Wextra task09.cpp -o task09

### Run Command

.\task09.exe

## Testing

Five test cases were used to validate the metro fare system.

| Test Case | Scenario | Expected Result |
|---|---|---|
| 1 | Normal Inner Zone | Rs 10, Allowed |
| 2 | Peak Outer Zone | Rs 36, Allowed |
| 3 | Student Concession | Rs 15, Allowed |
| 4 | Minimum Balance Boundary | Rs 50 remains, Allowed |
| 5 | Insufficient Balance | Rs 40 remains, Not Allowed |

## Result

The metro fare calculation was successfully implemented and tested using multiple scenarios.

The tests covered normal fare calculation, peak-hour surcharge, student concession, the exact Rs 50 minimum-balance boundary, and insufficient-balance rejection.

All expected test cases produced the correct results.

## Evidence

- Task09_Test1.png
- Task09_Test2.png
- Task09_Test3.png
- Task09_Test4.png
- Task09_Test5.png