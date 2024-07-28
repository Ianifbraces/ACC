#ifndef EMPLOYEEINFO_H
#define EMPLOYEEINFO_H

#include <string>

using namespace std;

class EmployeeInfo {
private: // Private data members
    int employeeID; // Employee ID
    string employeeName; // Employee name

public:
    // Constructor
    EmployeeInfo(int id, const string &name) : employeeID(id), employeeName(name) {} // Initialize the data members

    // Getters
    int getID() const { return employeeID; } // Return the employee ID
    string getName() const { return employeeName; } // Return the employee name

    // Setters
    void setID(int id) { employeeID = id; } // Set the employee ID
    void setName(const string &name) { employeeName = name; } // Set the employee name

    // Overload comparison operators for sorting
    bool operator<(const EmployeeInfo &other) const { return employeeID < other.employeeID; } // Compare employee IDs
    bool operator>(const EmployeeInfo &other) const { return employeeID > other.employeeID; } // Compare employee IDs
    bool operator==(const EmployeeInfo &other) const { return employeeID == other.employeeID; } // Compare employee IDs
};

#endif // EMPLOYEEINFO_H
