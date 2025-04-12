#include "merge_sort.h"
#include <iostream>

// Comparator dispatcher based on field index
bool compare_employees(const Employee& a, const Employee& b, int field) {
    switch (field) {
        case 0:  return a.employee_id < b.employee_id;
        case 1:  return a.last_name < b.last_name;
        case 2:  return a.first_name < b.first_name;
        case 3:  return a.street_address < b.street_address;
        case 4:  return a.city < b.city;
        case 5:  return a.province < b.province;
        case 6:  return a.postal_code < b.postal_code;
        case 7:  return a.phone < b.phone;
        case 8:  return a.gender < b.gender;
        case 9:  return a.age < b.age;
        case 10: return a.dependents < b.dependents;
        case 11: return a.department < b.department;
        case 12: return a.union_member < b.union_member;
        case 13: return a.hourly_rate < b.hourly_rate;
        default: return false;
    }
}

void merge(std::vector<Employee>& arr, int left, int mid, int right, int field) {
    auto n1 = mid - left + 1;
    auto n2 = right - mid;

    std::vector<Employee> L(n1);
    std::vector<Employee> R(n2);

    for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (compare_employees(L[i], R[j], field)) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void merge_sort_internal(std::vector<Employee>& arr, int left, int right, int field) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort_internal(arr, left, mid, field);
        merge_sort_internal(arr, mid + 1, right, field);
        merge(arr, left, mid, right, field);
    }
}

void merge_sort(std::vector<Employee>& arr, int field) {
    merge_sort_internal(arr, 0, arr.size() - 1, field);
}