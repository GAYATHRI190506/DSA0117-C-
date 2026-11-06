# DSA01-192472074-Assignment3

## Data Structures and Algorithms – Assignment 3

### CO3 – Constructors, Destructors and Operator Overloading

**Student Name:** Madaraboina Gayathri  
**Register Number:** 192472074  
**Course:** Data Structures and Algorithms  
**Assignment:** Assignment 3 – CO3  
**Marks:** 50  

---

## 1. Assignment Overview

This assignment focuses on object-oriented programming concepts in C++, particularly:

- Constructors and constructor overloading
- Copy constructors
- Shallow and deep copying
- Dynamic constructors
- Destructors
- Dynamic memory management
- Operator overloading
- Prefix and postfix operators
- Comparison operators
- Subscript operator
- Stream insertion and extraction operators
- Rules and limitations of operator overloading
- Complex number arithmetic
- AC impedance calculations using complex numbers

All programs were implemented, compiled, executed, and tested using C++17.

---

## 2. Software and Tools Used

- **Programming Language:** C++
- **Standard:** C++17
- **Compiler:** GNU G++
- **IDE/Editor:** Visual Studio Code
- **Operating System:** Windows
- **Terminal:** PowerShell
- **Version Control:** Git
- **Repository:** GitHub

Compilation was performed using:

```text
g++ -std=c++17 -Wall -Wextra
```

---

# 3. Assignment Structure

```text
Assignment3/
│
├── Task01/
│   ├── task01.cpp
│   ├── reorder_test.cpp
│   ├── default_test.cpp
│   └── explicit_test.cpp
│
├── Task02/
│   ├── task02.cpp
│   ├── shallow_test.cpp
│   ├── self_assignment_test.cpp
│   ├── copy_count_test.cpp
│   └── timing_test.cpp
│
├── Task03/
│   ├── task03.cpp
│   ├── logger_test.cpp
│   ├── leak_test.cpp
│   ├── delete_test.cpp
│   └── zero_test.cpp
│
├── Task04/
│   ├── task04.cpp
│   ├── carry_borrow_test.cpp
│   ├── input_test.cpp
│   └── bill_test.cpp
│
├── Task05/
│   ├── task05.cpp
│   ├── counter_test.cpp
│   └── increment_timing.cpp
│
├── Task06/
│   ├── task06.cpp
│   ├── copy_test.cpp
│   ├── edge_test.cpp
│   └── operator_rules.cpp
│
├── Task07/
│   ├── task07.cpp
│   ├── zero_division_test.cpp
│   ├── rlc_test.cpp
│   └── parallel_rlc_test.cpp
│
├── .gitignore
└── README.md
```

---

# 4. Task 01 – Constructors and Constructor Overloading

## Objective

To implement a `Book` class demonstrating:

- Default constructor
- Parameterized constructor
- Constructor overloading
- Delegating constructors
- Constructor initialization lists
- Input validation

## Implementation

The `Book` class contains:

- `title`
- `author`
- `copies`

Different constructors were implemented to create objects with different combinations of information.

## Tests Performed

### Default Constructor

Creates a book with empty title and author and zero copies.

### Parameterized Constructor

Creates a book using title, author, and number of copies.

### Title-only Constructor

Uses default values for author and copies.

### Title and Author Constructor

Uses zero as the default number of copies.

### Invalid Input Test

A negative number of copies is converted to zero.

### Initialization Order Test

A separate program was compiled using `-Wreorder` to verify member initialization order.

### Default Constructor Availability Test

An array of objects was tested when no default constructor was provided, demonstrating the resulting compilation error.

## Result

All valid constructor implementations executed successfully and constructor behavior was verified.

---

# 5. Task 02 – Copy Constructors: Shallow and Deep Copies

## Objective

To understand:

- Copy constructors
- Shallow copying
- Deep copying
- Copy assignment
- Self-assignment
- Dynamic memory ownership
- Rule of Three

The `Prescription` class dynamically allocates memory for medicine names.

## Deep Copy

The copy constructor allocates separate memory and copies every medicine.

Therefore, modifying one object does not affect another.

## Copy Assignment

The assignment operator:

1. Checks for self-assignment.
2. Allocates new memory.
3. Copies the contents.
4. Deletes the previous memory.
5. Updates the object.

## Tests Performed

- Shallow copy behavior
- Deep copy behavior
- Copy constructor
- Copy assignment
- Self-assignment
- Copy counting
- Copy constructor timing

## Timing Test

The copy operation was tested for different numbers of medicines:

```text
Medicines: 10
Medicines: 1000
Medicines: 100000
```

The deep-copy operation has:

**Time Complexity:** O(n)

**Extra Space Complexity:** O(n)

## Result

Deep copying was successfully implemented and verified.

---

# 6. Task 03 – Dynamic Constructors and Destructors

## Objective

To demonstrate:

- Dynamic memory allocation
- Dynamic constructors
- Destructors
- 2D dynamic arrays
- `new` and `delete`
- `new[]` and `delete[]`
- Object lifetime
- RAII

A dynamic seat map was implemented.

## Features

- Dynamic number of rows
- Dynamic number of columns
- Seat booking
- Seat cancellation
- Detection of already booked seats
- Detection of already available seats
- Destructor-based memory release

## Tests Performed

### Seat Map Test

Seats were dynamically allocated and booking/cancellation operations were tested.

### Destructor Order Test

Objects were created inside nested/block scopes to observe destruction order.

Objects were destroyed in reverse order of construction.

### Memory Release Test

The destructor was tested to ensure dynamically allocated memory was released.

### `delete[]` Test

A dynamically allocated array was released correctly using `delete[]`.

### Zero-row Test

A zero-row configuration was tested to ensure the program handled the case safely.

## Result

Dynamic allocation and destructor-based memory management worked correctly.

---

# 7. Task 04 – Arithmetic and Stream Operators

## Objective

To implement a `Money` class using:

```text
long long paise
```

The following operators were overloaded:

- `+`
- `-`
- `+=`
- `==`
- `<`
- `<<`
- `>>`

## Features

The class stores money internally as paise to avoid floating-point precision problems.

Example:

```text
Rs.12.50 = 1250 paise
```

## Tests Performed

### Addition

```text
Rs.12.50 + Rs.2.75 = Rs.15.25
```

### Subtraction

```text
Rs.12.50 - Rs.2.75 = Rs.9.75
```

### Compound Assignment

The `+=` operator was tested successfully.

### Comparison

Equality and less-than comparisons were tested.

### Negative Result

Negative money formatting was tested.

### Carry and Borrow

Carry and borrow behavior was verified.

### Stream Input

The `>>` operator was tested using decimal money input.

### Bill Calculation

Multiple money values were added to calculate a total bill.

## Result

Arithmetic and stream operators worked correctly.

---

# 8. Task 05 – Increment, Comparison and Subscript Operators

## Objective

To implement:

- Prefix increment
- Postfix increment
- Equality comparison
- Less-than comparison
- Subscript operator

## Time Class

The `Time` class supports:

```text
++time
time++
```

Time normalization was implemented so that 60 minutes become one hour.

## Playlist Class

The `Playlist` class implements the `[]` operator for accessing and modifying songs.

Invalid indexes are detected using exception handling.

## Tests Performed

- Prefix increment
- Postfix increment
- Equality comparison
- Less-than comparison
- Playlist indexing
- Playlist modification
- Invalid index handling
- Counter behavior
- Increment timing

## Increment Timing

One million prefix and postfix increments were performed.

```text
Iterations: 1000000
Prefix final value: 1000000
Postfix final value: 1000000
```

The measured execution time can vary depending on the system and compiler optimization.

## Result

All increment, comparison, and subscript operations were successfully tested.

---

# 9. Task 06 – Text Class and Operator Overloading

## Objective

To implement a `Text` class using a dynamically allocated character array.

The class demonstrates the Rule of Three:

- Copy constructor
- Copy assignment operator
- Destructor

## Operators Implemented

- `+`
- `==`
- `!=`
- `<<`

## Deep Copy

The copy constructor and assignment operator allocate independent memory.

Therefore, modifying the copied object does not modify the original object.

## Tests Performed

### Concatenation

```text
Hello + World = Hello World
```

### Equality

Two text objects were compared using `==`.

### Inequality

Two different text objects were compared using `!=`.

### Deep Copy

The copy was modified independently from the original.

### Self-assignment

Self-assignment was tested safely.

### Empty Text

Empty strings were tested.

### Long Text

Long dynamically allocated text was tested.

### Non-overloadable Operators

The following operators were identified as non-overloadable:

```text
::
.
.*
?:
sizeof
```

### std::string Comparison

`std::string` equality comparison was also tested.

## Result

Dynamic character storage and all required operator overloads were successfully tested.

---

# 10. Task 07 – Complex Number Class

## Objective

To implement a Complex Number class for arithmetic and AC impedance calculations.

## Constructors

The class supports:

- Default constructor
- Constructor from real number
- Constructor from real and imaginary parts

## Operators Implemented

- `+`
- `-`
- `*`
- `/`
- `==`
- `<<`

## Complex Arithmetic

The following operations were tested:

```text
Addition
Subtraction
Multiplication
Division
Equality
```

For example:

```text
c1 = 3 + 4j
c2 = 1 + 2j
```

Results:

```text
c1 + c2 = 4 + 6j
c1 - c2 = 2 + 2j
c1 * c2 = -5 + 10j
c1 / c2 = 2.20 - 0.40j
```

## Division-by-Zero Protection

Division by a zero complex number was tested.

The implementation safely detects a zero denominator and returns a zero complex number instead of performing invalid division.

## RLC Impedance

The Complex class was applied to AC circuit calculations.

### Inductive Impedance

```text
ZL = jωL
```

### Capacitive Impedance

```text
ZC = -j/(ωC)
```

### Series RLC

```text
Z = R + ZL + ZC
```

The series RLC calculation was successfully tested.

### Parallel RLC

Parallel impedance was calculated using admittance:

```text
1/Z = 1/ZR + 1/ZL + 1/ZC
```

The parallel RLC calculation was successfully tested.

## Result

Complex arithmetic and RLC impedance calculations were successfully implemented and verified.

---

# 11. Overall Testing Summary

| Task | Main Concept | Status |
|---|---|---|
| Task 01 | Constructors | Completed |
| Task 02 | Copy Constructor / Deep Copy | Completed |
| Task 03 | Dynamic Constructor / Destructor | Completed |
| Task 04 | Arithmetic and Stream Operators | Completed |
| Task 05 | Increment / Comparison / Subscript | Completed |
| Task 06 | Text / Dynamic Memory / Operators | Completed |
| Task 07 | Complex Numbers / RLC | Completed |

---

# 12. Complexity Summary

| Operation | Complexity |
|---|---|
| Constructor initialization | O(1) for fixed fields |
| Deep copy of n elements | O(n) |
| Shallow pointer copy | O(1) |
| Dynamic seat map allocation | O(rows × columns) |
| Text copy | O(n) |
| Text concatenation | O(n + m) |
| Complex arithmetic | O(1) |
| Money arithmetic | O(1) |
| Playlist indexing | O(1) |
| Prefix/Postfix increment | O(1) |

---

# 13. Memory Management

The programs demonstrate responsible dynamic memory management using:

```cpp
new
delete
new[]
delete[]
```

Destructors are used to release dynamically allocated resources.

Deep-copy implementations ensure that objects owning dynamic memory do not accidentally share the same memory.

Self-assignment checks prevent unnecessary deletion and reallocation.

---

# 14. Compilation Standard

All programs were compiled using:

```text
g++ -std=c++17 -Wall -Wextra
```

Timing experiments were additionally compiled with optimization where required:

```text
g++ -std=c++17 -O2 -Wall -Wextra
```

---

# 15. GitHub Submission

Repository naming format:

```text
DSA01-192472074-Assignment3
```

The repository contains:

```text
Task01
Task02
Task03
Task04
Task05
Task06
Task07
README.md
.gitignore
```

Each task contains its implementation files and supporting test programs.

Progressive Git commits are maintained throughout the assignment.

---

# 16. Learning Outcomes

After completing this assignment, the following concepts were practiced:

1. Constructor overloading and delegating constructors.
2. Initialization lists and initialization order.
3. Copy constructors and copy assignment.
4. Shallow versus deep copying.
5. Dynamic memory allocation and deallocation.
6. Destructor behavior and object lifetime.
7. Rule of Three.
8. Arithmetic operator overloading.
9. Stream insertion and extraction operators.
10. Prefix and postfix operator overloading.
11. Comparison and subscript operators.
12. Operator overloading rules and limitations.
13. Dynamic character-array management.
14. Complex number arithmetic.
15. Application of operator overloading to RLC circuit calculations.

---

# 17. Conclusion

Assignment 3 successfully demonstrates the practical use of constructors, destructors, dynamic memory management, copy semantics, and operator overloading in C++.

All seven tasks were implemented, compiled, executed, and tested individually. Additional test programs were used to verify edge cases such as negative values, self-assignment, empty strings, invalid indexes, zero-sized allocations, division by zero, carry/borrow operations, and RLC impedance calculations.

The completed implementation provides practical understanding of object lifetime, resource ownership, deep copying, operator behavior, and object-oriented design in C++.