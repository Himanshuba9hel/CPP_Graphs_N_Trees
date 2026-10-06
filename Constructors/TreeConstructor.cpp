#include <cmath>
#include <queue>

#include "TreeConstructor.h"

TreeConstructor::TreeConstructor(int data) {
    root = new Node(data);
}

Node *TreeConstructor::create_node(int data = 0, Node* left = nullptr, Node* right = nullptr)
{
    Node *myNode = new Node(data, left, right);
    return myNode;
}

Node *TreeConstructor::get_root(){
    return root;
}

void TreeConstructor::balanceInsert(Node* root, int data){
    std::queue<Node*> childNodes;
    childNodes.push(root);
    while(!childNodes.empty()){
        if(insert(childNodes.front(),data)){
            break;
        }else{
            childNodes.push(childNodes.front()->left);
            childNodes.push(childNodes.front()->right);
            childNodes.pop();
        }
    }
}

bool TreeConstructor::insert(Node* node, int data){
    if(node->left == nullptr || node->right == nullptr){
        if(node->left == nullptr){
            node->left = new Node(data);
        }else{
            node->right = new Node(data);
        }
        return true;
    }
    return false;
}
