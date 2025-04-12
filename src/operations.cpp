/*
* File: operations.cpp
* Description: Handles output file creation and formatted display of employee data.
*              Saves sorted results to ../output/employees.txt.
*/

#include "operations.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>

// Always returns the single output path
std::string get_output_filename() {
    return "output/employees.txt";
}

// Create ../output folder cross-platform
void ensure_output_folder_exists() {
#ifdef _WIN32
    system("mkdir ../output >nul 2>&1");
#else
    system("mkdir -p ../output");
#endif
}

// Save sorted results to ../output/employees.txt
#include <iomanip>

bool save_sorted_employees(const std::vector<Employee>& employees) {
    ensure_output_folder_exists();

    std::string output_file = "output/employees.txt";
    std::ofstream out(output_file);

    if (!out) {
        std::cerr << "Error: Unable to create " << output_file << std::endl;
        return false;
    }

    // Column headers
    out << std::left
        << std::setw(10) << "ID"       << ' '
        << std::setw(12) << "Last"     << ' '
        << std::setw(12) << "First"    << ' '
        << std::setw(22) << "Address"  << ' '
        << std::setw(18) << "City"     << ' '
        << std::setw(6)  << "Prov"     << ' '
        << std::setw(10) << "Postal"   << ' '
        << std::setw(15) << "Phone"    << ' '
        << std::setw(3)  << "G"        << ' '
        << std::setw(5)  << "Age"      << ' '
        << std::setw(4)  << "Dep"      << ' '
        << std::setw(12) << "Dept"     << ' '
        << std::setw(2)  << "U"        << ' '
        << std::setw(7)  << "Rate"
        << '\n';

    out << std::string(150, '-') << '\n';

    // Each employee row
    for (const auto& emp : employees) {
        out << std::left
            << std::setw(10) << emp.employee_id     << ' '
            << std::setw(12) << emp.last_name        << ' '
            << std::setw(12) << emp.first_name       << ' '
            << std::setw(22) << emp.street_address   << ' '
            << std::setw(18) << emp.city             << ' '
            << std::setw(6)  << emp.province         << ' '
            << std::setw(10) << emp.postal_code      << ' '
            << std::setw(15) << emp.phone            << ' '
            << std::setw(3)  << emp.gender           << ' '
            << std::setw(5)  << emp.age              << ' '
            << std::setw(4)  << emp.dependents       << ' '
            << std::setw(12) << emp.department        << ' '
            << std::setw(2)  << emp.union_member     << ' '
            << std::setw(7)  << std::fixed << std::setprecision(2) << emp.hourly_rate
            << '\n';
    }

    std::cout << "Sorted table saved to: " << output_file << "\n";
    return true;
}

// Trims long strings for display (adds ... if too long)
std::string trim_display(const std::string& str, size_t width) {
    return str.length() <= width ? str : str.substr(0, width - 3) + "...";
}

// Print a table of the first n employees
void print_first_n_employees(const std::vector<Employee>& employees, int n, const std::string& title) {
    std::cout << "\n" << title << " (showing first " << std::min(n, (int)employees.size()) << " of " << employees.size() << " records)\n";
    std::cout << std::string(120, '-') << '\n';

    std::cout << std::left
              << std::setw(10) << "ID"      << ' '
              << std::setw(12) << "Last"    << ' '
              << std::setw(12) << "First"   << ' '
              << std::setw(20) << "City"    << ' '
              << std::setw(4)  << "Prov"    << ' '
              << std::setw(14) << "Phone"   << ' '
              << std::setw(4)  << "G"       << ' '
              << std::setw(4)  << "Age"     << ' '
              << std::setw(4)  << "Dep"     << ' '
              << std::setw(12) << "Dept"    << ' '
              << std::setw(2)  << "U"       << ' '
              << std::setw(6)  << "Rate"
              << '\n';

    std::cout << std::string(120, '-') << '\n';

    for (int i = 0; i < n && i < (int)employees.size(); ++i) {
        const auto& emp = employees[i];
        std::cout << std::setw(10) << trim_display(emp.employee_id, 10) << ' '
                  << std::setw(12) << trim_display(emp.last_name, 12)   << ' '
                  << std::setw(12) << trim_display(emp.first_name, 12)  << ' '
                  << std::setw(20) << trim_display(emp.city, 20)        << ' '
                  << std::setw(4)  << emp.province                      << ' '
                  << std::setw(14) << emp.phone                         << ' '
                  << std::setw(4)  << emp.gender                        << ' '
                  << std::setw(4)  << emp.age                           << ' '
                  << std::setw(4)  << emp.dependents                    << ' '
                  << std::setw(12) << trim_display(emp.department, 12)  << ' '
                  << std::setw(2)  << emp.union_member                  << ' '
                  << std::setw(6)  << std::fixed << std::setprecision(2) << emp.hourly_rate
                  << '\n';
    }
}

// Full display function (if needed)
void print_employees_full(const std::vector<Employee>& employees) {
    print_first_n_employees(employees, (int)employees.size(), "Sorted Employee List (Full)");
}