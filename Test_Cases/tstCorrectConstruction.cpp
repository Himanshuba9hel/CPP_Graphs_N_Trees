#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include "../Constructors/TreeConstructor.h"
using namespace testing;

TEST(TreeConstructorTest, CorrectConstruction)
{
    TreeConstructor *tree = new TreeConstructor(10);
    Node* node_right = tree->create_node(3, nullptr, nullptr);
    Node* node_left = tree->create_node(2, nullptr, nullptr);
    Node* node = tree->create_node(1, node_left, node_right);

    // Assertions check out safely now
    EXPECT_EQ(node->left->data, 2);
    EXPECT_EQ(node->right->data, 3);

    // Clean up dynamically allocated memory
    delete node_left;
    delete node_right;
    delete node;
    delete tree;
}

