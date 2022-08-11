#include <iostream>
#include <string>
#include "bst.h"

using namespace std;

int main (int argc, char** argv) {
    
    cout << endl << endl;
    cout << "Integer Tree:";
    cout << endl << endl;
    // Create a BST with an inital root of 25
    BST<int>* tree = new BST<int>(25);
    tree->Insert(20);
    tree->Insert(12);
    tree->Insert(-10);
    tree->Insert(50);
    
    tree->Print();
    cout << endl << endl;
    
    tree->Remove(12);
    tree->Print();
    cout << endl << endl;
    
    Node<int>* node = tree->Find(2);
    if (node == nullptr) {
        cout << "not found" << endl;
    } else {
        cout << node->data << endl;
    }
    delete(tree);
    
    cout << endl << endl << endl << endl;
    cout << "Character Tree:";
    cout << endl << endl;
    
    BST<char>* cTree = new BST<char>('k');
    cTree->Print();
    cout << endl << endl;
    
    cTree->Insert('a');
    cTree->Insert('z');
    cTree->Insert('d');
    cTree->Insert('s');
    
    cTree->Print();
    cout << endl << endl;
    
    cTree->Remove('k');
    
    cTree->Print();
    cout << endl << endl;
    
    delete(cTree);
}
