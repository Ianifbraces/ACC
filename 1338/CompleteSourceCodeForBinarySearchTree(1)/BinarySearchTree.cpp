//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** @file BinarySearchTree.cpp */
#include "BinarySearchTree.h"

using namespace std;

BinaryNode* BinarySearchTree::insert(BinaryNode *node, const EmployeeInfo &employee) {
    if (node == nullptr) {
        return new BinaryNode(employee); // Create a new node
    }
    if (employee < node->getData()) {
        node->setLeftChild(insert(node->getLeftChild(), employee)); // Recursively insert into the left subtree
    } else if (employee > node->getData()) {
        node->setRightChild(insert(node->getRightChild(), employee)); // Recursively insert into the right subtree
    }
    return node;
}

BinaryNode* BinarySearchTree::remove(BinaryNode *node, int employeeID) {
    if (node == nullptr) {
        return nullptr;// Return if the tree is empty
    }
    if (employeeID < node->getData().getID()) {
        node->setLeftChild(remove(node->getLeftChild(), employeeID));// Recursively remove from the left subtree
    } else if (employeeID > node->getData().getID()) {
        node->setRightChild(remove(node->getRightChild(), employeeID));// Recursively remove from the right subtree
    } else {
        if (node->getLeftChild() == nullptr) {
            BinaryNode *temp = node->getRightChild();// If the node has only one child
            delete node;
            return temp;
        } else if (node->getRightChild() == nullptr) {// If the node has only one child
            BinaryNode *temp = node->getLeftChild();
            delete node;
            return temp;
        } else {// If the node has two children
            BinaryNode *temp = findMin(node->getRightChild());// Find the inorder successor
            node->setData(temp->getData());// Copy the inorder successor's data to this node
            node->setRightChild(remove(node->getRightChild(), temp->getData().getID()));// Delete the inorder successor
        }
    }
    return node;
}

BinaryNode* BinarySearchTree::search(BinaryNode *node, int employeeID) const { // Search for a node with the given employee ID
    if (node == nullptr || node->getData().getID() == employeeID) { // Return the node if it is found
        return node;
    }
    if (employeeID < node->getData().getID()) {
        return search(node->getLeftChild(), employeeID); // Recursively search the left subtree
    } else {
        return search(node->getRightChild(), employeeID); // Recursively search the right subtree
    }
}

void BinarySearchTree::inorder(BinaryNode *node) const {// Inorder traversal
    if (node != nullptr) {
        inorder(node->getLeftChild());// Recursively traverse the left subtree
        cout << "Employee ID: " << node->getData().getID() << ", Name: " << node->getData().getName() << endl;// Display the node
        inorder(node->getRightChild());// Recursively traverse the right subtree
    }
}

BinaryNode* BinarySearchTree::findMin(BinaryNode *node) const {// Find the node with the minimum value
    while (node->getLeftChild() != nullptr) {
        node = node->getLeftChild();// Traverse the left subtree
    }
    return node;
}

void BinarySearchTree::insert(const EmployeeInfo &employee) {
    root = insert(root, employee);// Insert the employee into the tree
}

void BinarySearchTree::remove(int employeeID) {
    root = remove(root, employeeID);// Remove the employee from the tree
}

EmployeeInfo BinarySearchTree::search(int employeeID) const {
    BinaryNode *result = search(root, employeeID);// Search for the employee
    if (result != nullptr) {
        return result->getData();// Return the employee if found
    }
    return EmployeeInfo(-1, "");  // Return a default EmployeeInfo if not found
}

void BinarySearchTree::display() const {// Display the tree
    inorder(root);// Perform an inorder traversal
}
