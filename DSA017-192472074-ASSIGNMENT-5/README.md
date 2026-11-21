# C++ Assignment 5 – CO5
## Reliable Software with Runtime Polymorphism and Exceptions

**Course:** C++ Programming  
**Assignment:** Assignment 5  
**Course Outcome:** CO5 – Reliable Software with Runtime Polymorphism and Exceptions  
**Language:** C++17  
**Compiler:** GCC (MinGW)  
**IDE:** Visual Studio Code  
**Operating System:** Windows 11

---

## 1. Introduction

This assignment focuses on developing reliable and extensible C++ applications using runtime polymorphism, inheritance, virtual functions, exception handling, and performance benchmarking.

A hospital billing system is used as the primary example to demonstrate object-oriented design, error handling, memory safety, and software extensibility.

## 2. Objectives

- Understand runtime polymorphism and virtual functions.
- Implement abstract classes and inheritance.
- Understand the importance of virtual destructors.
- Implement exception handling and custom exceptions.
- Compare return codes and exception handling.
- Benchmark virtual functions, switch statements, and `std::variant`.
- Develop an extensible hospital billing system.
- Evaluate software design for production requirements.

## 3. Technologies Used

| Technology | Purpose |
|---|---|
| C++17 | Programming language |
| GCC / MinGW | C++ compiler |
| Visual Studio Code | Development environment |
| PowerShell | Compilation and execution |
| Standard Template Library | Vectors, smart pointers, variant |
| `<chrono>` | Performance measurement |

## 4. Assignment Structure

```text
Assignment5/
│
├── Task01/
│   ├── A1_design.txt
│   ├── A1_pseudocode.txt
│   └── A1_bill_hierarchy.cpp
│
├── Task02/
│   ├── A2_notes.txt
│   └── A2_virtual_destructor.cpp
│
├── Task03/
│   ├── A3_payer_design.txt
│   └── A3_payer_demo.cpp
│
├── Task04/
│   └── A4 source and design files
│
├── Task05/
│   ├── A5_recovery_design.txt
│   ├── A5_stack_unwinding.cpp
│   └── A5_rethrow_demo.cpp
│
├── Task06/
│   ├── B1_complete_code.cpp
│   ├── B1_full_billing.cpp
│   ├── B1_nonvirtual_total.cpp
│   └── B1_nonvirtual_destructor.cpp
│
├── Task07/
│   ├── B2_error_tests.cpp
│   ├── B2_prediction.cpp
│   ├── B2_complete_code.cpp
│   └── B2_analysis.txt
│
├── Task08/
│   ├── B3_correctness.cpp
│   ├── B3_benchmark.cpp
│   ├── B3_exception_benchmark.cpp
│   ├── B3_variant.cpp
│   └── B3_analysis.txt
│
├── Task09/
│   ├── B4_extended_system.cpp
│   ├── B4_backward_compatibility.cpp
│   ├── B4_exception_safety.cpp
│   └── B4_analysis.txt
│
└── README.md
```

*Note: Keep the actual filenames and folders consistent with the files in your project.*

## 5. Task Descriptions

### Task 01 – Hospital Billing Class Hierarchy
Designed a hospital billing hierarchy using inheritance and runtime polymorphism. Implemented different bill types and calculated individual and grand totals.

### Task 02 – Virtual Destructors
Demonstrated the importance of virtual destructors when deleting derived objects through base-class pointers.

### Task 03 – Payer Hierarchy
Implemented different payer categories, including self-pay, insurance, government schemes, and corporate tie-ups.

### Task 04 – Exception Handling
Explored billing errors, custom exceptions, and safe error-handling techniques.

### Task 05 – Stack Unwinding and Recovery
Demonstrated stack unwinding, object destruction, exception propagation, and rethrowing exceptions.

### Task 06 – B1: Runtime Polymorphism
Implemented polymorphic billing operations and compared virtual functions with non-virtual functions. Examined virtual destructor behaviour.

### Task 07 – B2: Exception Handling
Tested negative charges, claims exceeding coverage, unknown packages, invalid numeric input, and memory allocation failure. Implemented custom exceptions and compared error-handling approaches.

### Task 08 – B3: Performance Benchmarking
Compared virtual functions, switch statements, return codes, exceptions, and `std::variant` with `std::visit` using benchmark programs.

### Task 09 – B4: System Extension and Production Decision
Extended the billing system with new bill types and payer categories. Tested backward compatibility, exception safety, and production architecture considerations.

## 6. Compilation and Execution

Compile a C++ source file using:

```powershell
g++ -std=c++17 -Wall -Wextra filename.cpp -o filename.exe
```

Run the executable:

```powershell
.\filename.exe
```

For performance benchmarking, use optimization:

```powershell
g++ -std=c++17 -O2 -Wall -Wextra filename.cpp -o filename.exe
```

## 7. Testing and Validation

The assignment includes:

- Functional testing of different bill types.
- Validation of payer coverage calculations.
- Negative and invalid input testing.
- Exception propagation and recovery testing.
- Memory allocation failure testing.
- Runtime polymorphism correctness testing.
- Performance benchmarking with different input sizes.
- Backward compatibility testing.

## 8. Performance Evaluation

Performance measurements are collected from the benchmark programs on the development machine.

The measured results are used to compare:

- Virtual function dispatch and switch-based dispatch.
- Return-code handling and exception handling.
- Virtual functions, switch statements, and `std::variant`.

Actual timings depend on the hardware, compiler, optimization settings, and execution environment.

## 9. Conclusion

This assignment demonstrates how C++ runtime polymorphism, inheritance, virtual destructors, exception handling, and smart pointers can be used to develop reliable and extensible software.

The hospital billing system provides a practical example of adding new functionality while maintaining existing behaviour. Performance benchmarking also helps evaluate implementation choices based on application requirements.

---

**Submission:** Source code, design documents, analysis files, execution screenshots, and GitHub repository link.