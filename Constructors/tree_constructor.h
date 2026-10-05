#ifndef TREE_CONSTRUCTOR_H
#define TREE_CONSTRUCTOR_H

#include "node.h"

class Tree_Constructor
{
public:
    Tree_Constructor(int data = 0);
    Node* create_node(int data, Node* left, Node* right);
    Node* root = nullptr;
    Node* get_root();
    void balanceInsert(Node* root, int data);
    bool insert(Node* node,int data);
};

#endif // TREE_CONSTRUCTOR_H
