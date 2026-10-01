#ifndef NODE_H
#define NODE_H
#include <string>

struct Node
{
    int data = 0;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int _data): data(_data) {}
    Node(int _data, Node* _left): data(_data), left(_left) {}
    Node(int _data, Node* _left, Node* _right): data(_data), left(_left), right(_right) {}
    Node(Node* _left, Node* _right): left(_left), right(_right) {}
    Node(Node* _left): left(_left) {}
    Node() = default;
};

#endif // NODE_H
