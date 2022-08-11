#ifndef BST_H
#define BST_H

#include <iostream>

//Node struct to hold our data and pointers to the two leaves
//Can also use a class here, but since we want everything public
//Struct is easier
template <typename T>
struct Node {
    T data;
    Node* left;
    Node* right;
    Node(T data);
};

//Constructor
template <typename T>
Node<T>::Node(T data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
}
    
//Main BST Class
template <typename T>
class BST {
    public:
        Node<T>* root;
        BST();
        BST(T data);
        ~BST();
        Node<T>* Insert(T data);
        Node<T>* Find(T data);
        Node<T>* Remove(T data);
        void Empty();
        void Print();
    private:
        Node<T>* Insert(Node<T>* root, T data);
        Node<T>* Find(Node<T>* root, T data);
        Node<T>* Remove(Node<T>* root, T data);
        Node<T>* FindPredecessor(Node<T>* root);
        void Print(Node<T>* root);
        void Empty(Node<T>* root);
    
};

//Default constructor
template <typename T>
BST<T>::BST() {
    root = nullptr;
}

//Constructor with initial value for root
template <typename T>
BST<T>::BST(T data) {
    root = new Node<T>(data);
}

//Destructor to remove all heap objects
template <typename T>
BST<T>::~BST() {
    Empty();
}

template <typename T>
void BST<T>::Empty() {
    Empty(root);
    root = nullptr;
}

//Using postorder traveral to delete all objects on the heap
template <typename T>
void BST<T>::Empty(Node<T>* root) {
    if (root == nullptr) {
        return;
    } else {
        Empty(root->left);
        Empty(root->right);
        delete root;
    }
}

//Public Insert method
template <typename T>
Node<T>* BST<T>::Insert(T data) {
    return Insert(root, data);
}

//Private helper method
template <typename T>
Node<T>* BST<T>::Insert(Node<T>* root, T data) {
    if (root == nullptr) {
        root = new Node<T>(data);
        return root;
    }  else if (root->data == data) {
        //Already exists, return the existing object
        return root;
    } else if (root->data > data) {
        //Root data is greater than data to be inserted, so recursively insert on the left leaf
        root->left = Insert(root->left, data);
    } else{
        //Root data is less than data to be inserted, so recursively insert on the right leaf
        root->right =  Insert(root->right, data);
    }
    return root;
}

template <typename T>
Node<T>* BST<T>::Find(T data) {
    return Find(root, data);
}

template <typename T>
Node<T>* BST<T>::Find(Node<T>* root, T data) {
    if (root == nullptr) {
        return nullptr;
    }
    
    if (root->data == data) {
        return root;
    } else if (root->data > data) {
        return Find(root->left, data);
    } else {
        return Find(root->right, data);
    }
}

template <typename T>
Node<T>* BST<T>::Remove(T data) {
    root = Remove(root, data);
    return root;
}


template <typename T>
Node<T>* BST<T>::Remove(Node<T>* root, T data) {
    if (root == nullptr) {
        return nullptr;
    }
    
    //Recusively look for the node to be deleted
    if (root->data > data) {
        root->left = Remove(root->left, data);
    } else if (root->data < data) {
        root->right = Remove(root->right, data);
    } else {
        //Node was found
        //3 cases to handle now: node is a leaf, node has one child, and node has 2 children
        
        //Node is a leaf:
        if(root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        //Node has one child:
        } else if (root->right == nullptr) {
            Node<T>* temp = root->left;
            delete root;
            return temp;
        } else if (root->left == nullptr) {
            Node<T>* temp = root->right;
            delete root;
            return temp;
        //Node has two children:
        } else {
            Node<T>* pred = FindPredecessor(root->left);
            root->data = pred->data;
            root->left = Remove(root->left, pred->data);
        }
    }
    return root;
}

template <typename T>
Node<T>* BST<T>::FindPredecessor(Node<T>* root) {
    if (root->right == nullptr) {
        return root;
    } else {
        return FindPredecessor(root->right);
    }
}

template <typename T>
void BST<T>::Print() {
    if (root == nullptr) {
        std::cout << "Empty Tree" << std::endl;
        return;
    } else {
        Print(root);
    }
}

template <typename T>
void BST<T>::Print(Node<T>* root) {
    if (root == nullptr) {
        return;
    } else {
        Print(root->left);
        std::cout << root->data << " ";
        Print(root->right);
    }
}

#endif