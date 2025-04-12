Project Summary – PROG2400 Assignment 4: Merge Sort Employee Sorter
Author: Tsira Mamaladze
Course: PROG2400
Instructor: Brian Shewan
Submission: Assignment 4 – Merge Sort

Objective
The purpose of this assignment was to implement the Merge Sort algorithm to sort a structured list of employee records based on a chosen field. The program reads a tab-separated input file, performs sorting based on the user’s selection, displays the sorted output in a readable table, and saves the result to an output file.

Features
Accepts input file via user prompt
Supports sorting by:
  - 0: Employee ID
  - 9: Age
  - 11: Department
  - 13: Hourly Rate
Performs top-down recursive in-memory Merge Sort
Displays sorted output in a clean, aligned format
Saves result to ../output/employees.txt
Handles file loading errors and malformed input lines
File and function-level comments included for clarity

Merge Sort Implementation
- Implemented in merge_sort.cpp
- Uses in-memory recursion with temporary arrays (std::vector)

Testing & Data
- Input file: employees.txt contains 20 randomized employee records
- Fields include whitespace and variety in casing/values
- Sorting behavior is verified through both console output and output file inspection

Project Structure
project/
├── employees.txt
├── output/
│   └── employees.txt         ← Sorted result
├── employee.h / employee.cpp
├── merge_sort.h / merge_sort.cpp
├── operations.h / operations.cpp
└── main.cpp

How to Run
./mergesort

Prompts:
Enter employee data file (e.g. employees.txt):
Enter field number to sort by:
