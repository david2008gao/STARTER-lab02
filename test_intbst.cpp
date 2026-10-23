//test_intbst.cpp
//personally created test for CS 24 Lab

#include "intbst.h"

#include <iostream>
using namespace std;

void runtests(IntBST& bst){
    cout<<"begin tests:" << endl;

    bst.printPreOrder();
    cout << "printed preorder" << endl;
    bst.printInOrder();
    cout << "printed inorder" << endl;
    bst.printPostOrder();
    cout << "printed postorder" << endl;

    cout << "sum: " << bst.sum() << endl;
    cout << "count: " << bst.count() << endl;

    cout << "is 5 in tree? " << bst.contains(5) << endl;
    cout << "is 520 in tree? " << bst.contains(520) << endl;

    cout << "predecessor of 5: " << bst.getPredecessor(5) << endl;
    cout << "predecessor of 9: " << bst.getPredecessor(9) << endl;
    cout << "successor of 5: " << bst.getSuccessor(5) << endl;
    cout << "successor of 9: " << bst.getSuccessor(9) << endl;
    cout << "removing 5: " << bst.remove(5) << endl;
    cout << "removing 9: " << bst.remove(9) << endl;
    cout << "printing preorder: ";
    bst.printPreOrder();
    cout << endl;
}

int main() {
    IntBST bst1, bst2;

    cout << bst1.insert(5) << endl; //1
    cout << bst1.insert(5) << endl; //0
    cout << bst1.insert(3) << endl; //1
    bst1.insert(7);
    bst1.insert(1);
    bst1.insert(4);
    bst1.insert(9);
    bst1.insert(21);
    bst1.insert(6);

    runtests(bst1);
    runtests(bst2);

    return 1;
}