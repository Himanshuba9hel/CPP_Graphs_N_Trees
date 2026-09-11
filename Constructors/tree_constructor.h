#ifndef TREE_CONSTRUCTOR_H
#define TREE_CONSTRUCTOR_H

#include "node.h"

class Tree_Constructor
{
public:
    Tree_Constructor();
    Node* create_node(int data, Node* left, Node* right);
};

#endif // TREE_CONSTRUCTOR_H
