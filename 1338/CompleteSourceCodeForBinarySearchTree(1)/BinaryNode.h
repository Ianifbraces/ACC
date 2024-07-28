//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** A class of nodes for a link-based binary tree.
 Listing 16-2.
 @file BinaryNode.h */
 
#ifndef BINARYNODE_H
#define BINARYNODE_H

#include "EmployeeInfo.h"

using namespace std; 

class BinaryNode {
private: // Private data members
    EmployeeInfo data; // Employee data
    BinaryNode *leftChild; // Pointer to the left child
    BinaryNode *rightChild; // Pointer to the right child

public:
    // Constructor
    BinaryNode(const EmployeeInfo &employee) : data(employee), leftChild(nullptr), rightChild(nullptr) {} // Initialize the data members

    // Getters
    EmployeeInfo getData() const { return data; } // Return the employee data
    BinaryNode* getLeftChild() const { return leftChild; } // Return the left child
    BinaryNode* getRightChild() const { return rightChild; } // Return the right child

    // Setters
    void setData(const EmployeeInfo &employee) { data = employee; } // Set the employee data
    void setLeftChild(BinaryNode *left) { leftChild = left; } // Set the left child
    void setRightChild(BinaryNode *right) { rightChild = right; } // Set the right child
};

#endif // BINARYNODE_H
