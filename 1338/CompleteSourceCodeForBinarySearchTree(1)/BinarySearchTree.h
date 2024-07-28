//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

// Listing 16-4.

/** Link-based implementation of the ADT binary search tree.
 @file BinarySearchTree.h */
 
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "BinaryNode.h"
#include <iostream>
#include <queue>

using namespace std;

class BinarySearchTree {
private:
    BinaryNode *root;

    // Helper functions
    BinaryNode* insert(BinaryNode *node, const EmployeeInfo &employee);
    BinaryNode* remove(BinaryNode *node, int employeeID);
    BinaryNode* search(BinaryNode *node, int employeeID) const;
    void inorder(BinaryNode *node) const;
    BinaryNode* findMin(BinaryNode *node) const;

public:
    // Constructor
    BinarySearchTree() : root(nullptr) {}

    // Public member functions
    void insert(const EmployeeInfo &employee);
    void remove(int employeeID);
    EmployeeInfo search(int employeeID) const;
    void display() const;
};

#endif // BINARYSEARCHTREE_H
