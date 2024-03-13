#include "TreeInheritance.h"
#include "TreeNode.h"
#include <iostream>
using namespace std;


TreeNode* TreeInheritance::CreateNode(int val)
{
    TreeNode* NewNode = new TreeNode();

    NewNode->data = val;

    NewNode->left = nullptr;

    NewNode->right = nullptr;

    return NewNode;

}

TreeNode* TreeInheritance::InsertNodePrivate(TreeNode* node, int key) {
    if (node == NULL) {
        return CreateNode(key);
    }

    if (key < node->data) {
        node->left = InsertNodePrivate(node->left, key);
    }
    else {
        node->right = InsertNodePrivate(node->right, key);
    }

    return node;
}

void TreeInheritance::PrintTree(TreeNode* root)
{
    if (root == nullptr) {
        return;
    }

    cout << root->data << ", ";
    PrintTree(root->left);
    PrintTree(root->right);
}


TreeNode* TreeInheritance::FindMin(TreeNode* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}


// Delete a node


TreeNode* TreeInheritance::DeleteNodePrivate(TreeNode*& node, int value) {
    // Check if the node is null
    if (node == nullptr) {
        return; // If the node is null, return
    }

    // Check if the current node's value matches the value to be deleted
    if (node->data == value) {
        // If the node has no left child
        if (node->left == nullptr) {
            TreeNode* tmp = node->right;
            delete node;
            node = tmp; // Update the link to the deleted node
        }
        // If the node has no right child
        else if (node->right == nullptr) {
            TreeNode* tmp = node->left;
            delete node;
            node = tmp; // Update the link to the deleted node
        }
        // If the node has both left and right children
        else {
            // Find the minimum value node in the right subtree
            TreeNode* minRight = FindMin(node->right);
            // Replace the current node's value with the minimum value
            node->data = minRight->data;
            // Delete the minimum value node from the right subtree
            DeleteNodePrivate(node->right, minRight->data);
        }
    }
    // If the current node's value doesn't match the value to be deleted
    else {
        // If the value is greater than the current node's value, search in the right subtree
        if (value > node->data) {
            DeleteNodePrivate(node->right, value);
        }
        // If the value is less than the current node's value, search in the left subtree
        else {
            DeleteNodePrivate(node->left, value);
        }
    }
}
