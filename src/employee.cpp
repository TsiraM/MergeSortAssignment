/*
* File: employee.cpp
 * Description: Handles loading of employee records from tab-separated file.
 *              Uses exception-safe parsing and skips bad records gracefully.
 */

#include "employee.h"
#include <fstream>
#include <sstream>
#include <iostream>

// Load employee records from a tab-separated file
std::vector<Employee> load_employees(const std::string& filename) {
    std::vector<Employee> employees;
    std::ifstream infile(filename);

    if (!infile) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return employees;
    }

    std::string line;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);

        try {
            Employee emp;
            std::string token;
            // Read all 14 tab-separated fields
            std::getline(iss, emp.employee_id, '\t');
            std::getline(iss, emp.last_name, '\t');
            std::getline(iss, emp.first_name, '\t');
            std::getline(iss, emp.street_address, '\t');
            std::getline(iss, emp.city, '\t');
            std::getline(iss, emp.province, '\t');
            std::getline(iss, emp.postal_code, '\t');
            std::getline(iss, emp.phone, '\t');
            std::getline(iss, emp.gender, '\t');

            std::getline(iss, token, '\t');
            emp.age = std::stoi(token);  // may throw

            std::getline(iss, token, '\t');
            emp.dependents = std::stoi(token);  // may throw

            std::getline(iss, emp.department, '\t');
            std::getline(iss, emp.union_member, '\t');

            std::getline(iss, token, '\t');
            emp.hourly_rate = std::stod(token);  // may throw

            employees.push_back(emp);
        } catch (...) {
            std::cerr << "Skipping bad or incomplete line:\n  " << line << "\n";
        }
    }

    return employees;
}