#ifndef TREECONSTRUCTOR_H
#define TREECONSTRUCTOR_H

#include "node.h"
#include <vector>
class TreeConstructor
{
public:
    TreeConstructor(int data = 0);
    Node* create_node(int data, Node* left, Node* right);
    Node* root = nullptr;
    Node* get_root();
    void balanceInsert(Node* root, int data);
    void showTree(Node* root);
    bool insert(Node* node,int data);
    std::vector<std::vector<int> > getTreeData(Node *root);
};

#endif // TREECONSTRUCTOR_H
