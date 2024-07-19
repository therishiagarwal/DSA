#include <iostream>
#include <climits> // for INT_MIN

using namespace std;

// Node structure for a binary tree
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to check if a binary tree is a BST
bool isBinarySearchTree(TreeNode* root, int minValue = INT_MIN, int maxValue = INT_MAX) {
    // Base case: If the node is null, it is a valid BST
    if (root == nullptr) {
        return true;
    }

    // Check if the current node's value is within the valid range
    if (root->data <= minValue || root->data >= maxValue) {
        return false;
    }

    // Recursively check the left and right subtrees with updated ranges
    return isBinarySearchTree(root->left, minValue, root->data) && isBinarySearchTree(root->right, root->data, maxValue);
}

int main() {
    // Example usage:
    // Construct a sample binary tree (BST):
    //        3
    //       / \
    //      2   5
    //     / \
    //    1   4
    TreeNode* rootBST = new TreeNode(3);
    rootBST->left = new TreeNode(2);
    rootBST->right = new TreeNode(5);
    rootBST->left->left = new TreeNode(1);
    rootBST->left->right = new TreeNode(4);

    // Check if the tree is a BST
    bool isBST = isBinarySearchTree(rootBST);
    cout << "Is the tree a BST? " << (isBST ? "Yes" : "No") << endl;

    // Clean up memory (deallocating nodes in a real application)
    delete rootBST->left->left;
    delete rootBST->left->right;
    delete rootBST->left;
    delete rootBST->right;
    delete rootBST;

    return 0;
}
