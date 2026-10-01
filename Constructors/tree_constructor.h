#ifndef TREE_CONSTRUCTOR_H
#define TREE_CONSTRUCTOR_H

#include "node.h"

class Tree_Constructor
{
public:
    Tree_Constructor(int data);
    Node* create_node(int data, Node* left, Node* right);
    Node* root = nullptr;
    Node* get_root();
    bool insert(int data);
};

#endif // TREE_CONSTRUCTOR_H
