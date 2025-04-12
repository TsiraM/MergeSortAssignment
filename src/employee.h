/*
 *   This header defines the Employee structure and declares functions for loading.
 */
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <vector>

struct Employee {
    std::string employee_id;
    std::string last_name;
    std::string first_name;
    std::string street_address;
    std::string city;
    std::string province;
    std::string postal_code;
    std::string phone;
    std::string gender;
    int age;
    int dependents;
    std::string department;
    std::string union_member;
    double hourly_rate;
};

// Load employee records from a tab-separated file
std::vector<Employee> load_employees(const std::string& filename);

#endif