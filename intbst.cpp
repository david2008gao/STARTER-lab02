// intbst.cpp
// Implements class IntBST
// David Gao 10/23/2026

#include "intbst.h"

#include <iostream>
using std::cout;

// constructor sets up empty tree
IntBST::IntBST() { 
    root = nullptr;
}

// destructor deletes all nodes
IntBST::~IntBST() {

}

// recursive helper for destructor
void IntBST::clear(Node *n) {
    clear(n->left);
    clear(n->right);
    delete n;
}

// insert value in tree; return false if duplicate
bool IntBST::insert(int value) {
    if (!root) root = value;
    return insert(value, root); // REPLACE THIS NON-SOLUTION
}

// recursive helper for insert (assumes n is never 0)
bool IntBST::insert(int value, Node *n) {
    if (value == n->info) return false;
    if (value > n->info){
        if (!n->right){
            Node* newNode;
            newNode->info = value;
            n->right = newNode;
        }
        else{
            return insert(value, n->right);
        }
    }
    if (value < n->info){
        if (!n->left){
            Node* newNode;
            newNode->info = value;
            n->left = newNode;
        }
        else{
            return insert(value, n->left);
        }
    }

    return true; // REPLACE THIS NON-SOLUTION
}

// print tree data pre-order
void IntBST::printPreOrder() const {
    cout << "pre-order:"
    printPreOrder(root);
    //cout << "IMPLEMENT printPreOrder public method";; // IMPLEMENT HERE
}

// recursive helper for printPreOrder()
void IntBST::printPreOrder(Node *n) const {
    if (!n) return nullptr;
    cout << " " << n->info;
    printPreOrder(n->left);
    printPreOrder(n->right);

    //cout << "IMPLEMENT printPreOrder private helper method"; // IMPLEMENT HERE
}

// print tree data in-order, with helper
void IntBST::printInOrder() const {
    cout << "in-order:";
    printInOrder(root);
    //cout << "IMPLEMENT printInOrder public method"; // IMPLEMENT HERE
}
void IntBST::printInOrder(Node *n) const {
    if (!n) return nullptr;
    printPreOrder(n->left);
    cout << " " << n->info;
    printPreOrder(n->right);
    //cout << "IMPLEMENT IMPLEMENT printInOrder private helper method"; // IMPLEMENT HERE
}

// prints tree data post-order, with helper
void IntBST::printPostOrder() const {
    cout << "post-order:";
    printPostOrder(root);
    //cout << "IMPLEMENT printPostOrder public method"; // IMPLEMENT HERE
}

void IntBST::printPostOrder(Node *n) const {
    if (!n) return nullptr;
    printPreOrder(n->left);
    printPreOrder(n->right);
    cout << " " << n->info;
    //cout << "IMPLEMENT printPostOrder private helper method";// IMPLEMENT HERE
}

// return sum of values in tree
int IntBST::sum() const {
    return sum(root); // REPLACE THIS NON-SOLUTION
}

// recursive helper for sum
int IntBST::sum(Node *n) const {
    if (!n) return 0;
    return n->info + sum(n->left) + sum(n->right);
    //return -1; // REPLACE THIS NON-SOLUTION
}

// return count of values
int IntBST::count() const {
    return count(root); // REPLACE THIS NON-SOLUTION
}

// recursive helper for count
int IntBST::count(Node *n) const {
    if (!n) return 0;
    return 1 + count(n->left) + count(n->right);
    //return -1; // REPLACE THIS NON-SOLUTION
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
IntBST::Node* IntBST::getNodeFor(int value, Node* n) const{
    if (!n) return NULL;
    if (n->info == value) return n;
    Node* left = getNodeFor(value, n->left);
    if (left) return left;
    return getNodeFor(value, n->right);
    //return NULL; // REPLACE THIS NON-SOLUTION
}

// returns true if value is in the tree; false if not
bool IntBST::contains(int value) const {
    return getNodeFor(value, root); // REPLACE THIS NON-SOLUTION
}

// returns the Node containing the predecessor of the given value
IntBST::Node* IntBST::getPredecessorNode(int value) const{
    if(!root) return NULL;
    if(root->info == value) return NULL;
    Node* curr = root;
    while(curr){
        if(curr->left->info == value || curr -> right -> info == value) return curr;
        if(curr->info > value){
            curr = curr->right;
        }
        else{
            curr = curr->left;
        }
    }
    return NULL;
    //return NULL; // REPLACE THIS NON-SOLUTION
}

// returns the predecessor value of the given value or 0 if there is none
int IntBST::getPredecessor(int value) const{
    Node* prev = getPredecessorNode(value);
    if (prev) return prev -> info; 
    return 0;
    // REPLACE THIS NON-SOLUTION
}

// returns the Node containing the successor of the given value
IntBST::Node* IntBST::getSuccessorNode(int value) const{
    Node* curr = getNodeFor(value);
    if (!curr) return NULL;
    if (curr->right){
        curr = curr->right;
        while (curr->left){
            curr = curr -> left;
        }
        return curr;
    }
    Node* prev = getPredecessorNode(value);
    curr = getNodeFor(value);
    while(prev){
        if (prev->left == curr) return prev;
        curr = prev;
        prev = getPredecessorNode(prev->info);
    }
    return NULL; // REPLACE THIS NON-SOLUTION
}

// returns the successor value of the given value or 0 if there is none
int IntBST::getSuccessor(int value) const{
    Node* prev = getSuccessorNode(value);
    if (prev) return prev -> info; 
    return 0;
    // REPLACE THIS NON-SOLUTION
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool IntBST::remove(int value){
    Node* prev = getPredecessorNode(value);
    Node* curr = getNodeFor(value);
    if (!curr) return false;
    if (prev->left && prev->left == curr){
        if (curr -> left && curr -> right){
            Node* rightNode = curr->right;
            Node* temp = curr;
            curr = curr->left;
            delete temp;
            prev->left = curr;
            while (curr -> right){
                curr = curr -> right;
            }
            curr -> right = rightNode;
            return true;
        }
        if (curr -> left){
            Node* temp = curr->left;
            prev->left = temp;
            delete curr;
            return true;
        }
        if (curr -> right){
            Node* temp = curr->right;
            prev->left = temp;
            delete curr;
            return true;
        }
    }
    if (prev->right && prev->right == curr){
        if (curr -> left && curr -> right){
            Node* rightNode = curr->right;
            Node* temp = curr;
            curr = curr->left;
            delete temp;
            prev->right = curr;
            while (curr -> right){
                curr = curr -> right;
            }
            curr -> right = rightNode;
            return true;
        }
        if (curr -> left){
            Node* temp = curr->left;
            prev->right = temp;
            delete curr;
            return true;
        }
        if (curr -> right){
            Node* temp = curr->right;
            prev->right = temp;
            delete curr;
            return true;
        }
    }
    return false; // REPLACE THIS NON-SOLUTION
}
