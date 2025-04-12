/*
* Header for operations related to displaying and saving employee data.
*/

#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "employee.h"
#include <vector>
#include <string>

std::string get_output_filename();
bool save_sorted_employees(const std::vector<Employee>& employees);
std::string trim_display(const std::string& str, size_t width);

void print_first_n_employees(const std::vector<Employee>& employees, int n, const std::string& title);
void print_employees_full(const std::vector<Employee>& employees);

#endif // OPERATIONS_H
