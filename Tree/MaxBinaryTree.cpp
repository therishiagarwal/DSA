#include <iostream>


using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(NULL), right(NULL) {}
};

int findLargestElementInBinaryTree(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int leftMax = findLargestElementInBinaryTree(root->left);
    int rightMax = findLargestElementInBinaryTree(root->right);

    return max(root->data, max(leftMax, rightMax));
}

int main() {
    // Example usage:
    // Construct a sample binary tree:
    //        3
    //       / \
    //      5   2
    //     / \
    //    7   1
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(1);

    // Find and print the largest element in the binary tree
    int largestElement = findLargestElementInBinaryTree(root);
    cout << "Largest element in the binary tree: " << largestElement << endl;

    return 0;
}
