#include <cmath>
#include <queue>

#include "tree_constructor.h"

Tree_Constructor::Tree_Constructor(int data) {
    root = new Node(data);
}

Node *Tree_Constructor::create_node(int data = 0, Node* left = nullptr, Node* right = nullptr)
{
    Node *myNode = new Node(data, left, right);
    return myNode;
}

Node *Tree_Constructor::get_root(){
    return root;
}

void Tree_Constructor::balanceInsert(Node* root, int data){
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

bool Tree_Constructor::insert(Node* node, int data){
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
