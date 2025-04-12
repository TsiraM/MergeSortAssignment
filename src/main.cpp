/*
 * File: main.cpp
 * Author: Tsira Mamaladze
 * Description: Entry point of the Merge Sort Employee Sorter program.
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "employee.h"
#include "merge_sort.h"
#include "operations.h"

void show_intro() {
    std::cout << "=================================================\n";
    std::cout << "  Merge Sort Employee Sorter\n";
    std::cout << "  Author: Tsira Mamaladze\n";
    std::cout << "  PROG2400 - Assignment 4\n";
    std::cout << "=================================================\n";
    std::cout << "This program sorts an employee list by a selected\n";
    std::cout << "field using the Merge Sort algorithm.\n";
    std::cout << "The sorting is done in ascending order.\n\n";
}

void show_field_options() {
    std::cout << "\nEnter field number to sort by:\n";
    std::cout << "  0  - Employee ID\n";
    std::cout << "  9  - Age\n";
    std::cout << " 11  - Department\n";
    std::cout << " 13  - Hourly Rate\n";
    std::cout << "> ";
}

std::string resolve_filename(const std::string& base) {
    std::vector<std::string> paths = {
        base,
        "../" + base,
    };

    for (const auto& path : paths) {
        std::ifstream f(path);
        if (f.good()) {
            std::cout << "File found at: " << path << std::endl;
            return path;
        }
    }

    std::cerr << "File not found in known locations. Proceeding anyway...";
    return base;
}

int main() {
    show_intro();

    std::string filename;
    std::cout << "Enter employee data file (e.g. employees.txt): ";
    std::getline(std::cin, filename);
    filename = resolve_filename(filename);

    show_field_options();
    int field;
    std::cin >> field;

    if (field != 0 && field != 9 && field != 11 && field != 13) {
        std::cerr << "Error: Invalid field number. Must be 0, 9, 11, or 13.\n";
        return 1;
    }

    std::vector<Employee> employees = load_employees(filename);
    if (employees.empty()) {
        std::cerr << "Error: No employee data loaded from: " << filename << "\n";
        return 1;
    }

    print_first_n_employees(employees, 5, "Employee Preview (Before Sorting)");

    std::cout << "\nSorting " << employees.size() << " records by field " << field << "...\n" << std::endl;
    merge_sort(employees, field);

    print_first_n_employees(employees, 5, "Sorted Output (After Sorting)");

    if (save_sorted_employees(employees)) {
        std::cout << "\nSort complete. Output file saved.\n";
    }

    return 0;
}