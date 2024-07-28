/* 
-------------------------------------------------------------------------
Name:     		Ian Korrub
Date: 			7/24/2024
Lab #:		    4
Status: 		Completed
Class:			COSC 1338
-------------------------------------------------------------------------
Objectives
1.  Demonstrate the use of a binary search tree.
2.  Implement a binary search tree.
3.  Implement the following operations for a binary search tree:
    a.  Insert a new node.
    b.  Remove a node.
    c.  Search for a node.
    d.  Display the tree.
4.  Implement a binary search tree using a linked list.

Other files updated:

BinarySearchTree.h
expanded fuctionality to include search, insert, remove, and display functions

BinarySearchTree.cpp
expanded functionality to include search, insert, remove, and display functions

EmployeeInfo.h
created to include overloaded comparison operators

EmployeeInfo.cpp
created to include overloaded comparison operators
-------------------------------------------------------------------------
*/

#include "BinarySearchTree.h"
#include "EmployeeInfo.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    BinarySearchTree bst;

    // Example data
    bst.insert(EmployeeInfo(6702, "James B W Bevis"));
    bst.insert(EmployeeInfo(1255, "Romney Wordsworth"));
    bst.insert(EmployeeInfo(1071, "Revis Jacara"));
    bst.insert(EmployeeInfo(2390, "Clegg Forbes"));
    bst.insert(EmployeeInfo(1558, "Kalin Tros"));
    bst.insert(EmployeeInfo(7406, "Archibald Beechcroft"));
    bst.insert(EmployeeInfo(7562, "Penthor Mul"));
    bst.insert(EmployeeInfo(3004, "Bartlet Finchley"));
    bst.insert(EmployeeInfo(4922, "Latham Bine"));
    bst.insert(EmployeeInfo(8483, "Jeff Myrtlebank"));

    int choice;
    int id;
    string name;

    do {
        cout << "\nBinary Search Tree Operations Menu\n";
        cout << "1. Search for an ID\n";
        cout << "2. Display the tree\n";
        cout << "3. Add a new employee\n";
        cout << "4. Remove an employee\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Employee ID to search: ";
            cin >> id;
            {
                EmployeeInfo employee = bst.search(id);// search for the employee
                if (employee.getID() != -1) {
                    cout << "Employee found: " << employee.getName() << endl;// display the employee name
                } else {
                    cout << "Employee not found.\n";// display that the employee was not found
                }
            }
            break;
        case 2:
            cout << "Displaying the tree:\n";
            bst.display(); // display the tree
            break;
        case 3:
            cout << "Enter new Employee ID: "; // prompt the user to enter the employee ID
            cin >> id; // read the employee ID
            cout << "Enter Employee Name: "; // prompt the user to enter the employee name
            cin.ignore(); // ignore the newline character
            getline(cin, name); // read the employee name
            bst.insert(EmployeeInfo(id, name)); // insert the employee into the tree
            cout << "Employee added.\n";
            break;
        case 4:
            cout << "Enter Employee ID to remove: "; // prompt the user to enter the employee ID to remove
            cin >> id;
            bst.remove(id); // remove the employee from the tree
            cout << "Employee removed.\n";
            break;
        case 5:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 5); // repeat until the user chooses to exit

    return 0;
}
