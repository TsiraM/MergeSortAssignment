/*
* Merge Sort implementation for Employee records.
* Sorts based on selected field index using comparator dispatcher.
 */

#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <vector>
#include "employee.h"

// Merge sort function that accepts a comparator
void merge_sort(std::vector<Employee>& arr, int field);

#endif