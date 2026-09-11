#include "tree_constructor.h"

Tree_Constructor::Tree_Constructor() {}

Node *Tree_Constructor::create_node(int data = 0, Node* left = nullptr, Node* right = nullptr)
{

    Node *myNode = new Node(data);
    return myNode;
}
