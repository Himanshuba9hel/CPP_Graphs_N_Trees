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

std::vector<std::vector<int> > TreeConstructor::getTreeData(Node *root)
{
    std::vector<std::vector<int>> treeData;
    if(root == nullptr)
        return treeData;
    return treeData = std::vector<std::vector<int>>(1,std::vector<int>(1,root->data));
    std::queue<Node*>* nodeQueue = new std::queue<Node*>();
    nodeQueue->push(root);
    bool allChildNullptr = false;
    while(!allChildNullptr) {
        std::queue<Node*>* nextNodeQueue = new std::queue<Node*>();
        std::vector<int> currentLevelValue;
        while(nodeQueue->empty()){
            Node* node = nodeQueue->front();
            if(node->left == nullptr){
                nextNodeQueue->push(nullptr);
                nextNodeQueue->push(nullptr);
                currentLevelValue.push_back(NULL);
                currentLevelValue.push_back(NULL);
            }else{
                nextNodeQueue->push(nullptr);
                nextNodeQueue->push(nullptr);
                currentLevelValue.push_back(NULL);
                currentLevelValue.push_back(NULL);
            }
            if(node->right == nullptr){
                nextNodeQueue->push(nullptr);
                nextNodeQueue->push(nullptr);
                currentLevelValue.push_back(NULL);
                currentLevelValue.push_back(NULL);
            }
        }
    }
    Node* node = new Node(
                        12,
    new Node(12,nullptr,nullptr),new Node(12));
    // std::queue<int> treeNodes;
}

void TreeConstructor::showTree(Node *root)
{

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
