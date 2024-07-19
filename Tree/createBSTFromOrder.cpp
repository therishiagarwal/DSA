#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Create a map to store the index of each element in the inorder traversal
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderMap[inorder[i]] = i;
        }

        // Call the recursive helper function to build the tree
        return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inorderMap);
    }

private:
    TreeNode* buildTreeHelper(const vector<int>& preorder, int preStart, int preEnd,
                              const vector<int>& inorder, int inStart, int inEnd,
                              const unordered_map<int, int>& inorderMap) {
        // Base case: If the range is empty, return null
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }

        // Create a node with the current root value from preorder
        TreeNode* root = new TreeNode(preorder[preStart]);

        // Find the index of the root value in inorder
        int rootIndexInorder = inorderMap.at(root->val);

        // Calculate the size of the left subtree
        int leftSubtreeSize = rootIndexInorder - inStart;

        // Recursively build the left and right subtrees
        root->left = buildTreeHelper(preorder, preStart + 1, preStart + leftSubtreeSize,
                                     inorder, inStart, rootIndexInorder - 1, inorderMap);
        root->right = buildTreeHelper(preorder, preStart + leftSubtreeSize + 1, preEnd,
                                      inorder, rootIndexInorder + 1, inEnd, inorderMap);

        return root;
    }
};

// Helper function to perform inorder traversal of the tree (for verification)
void inorderTraversal(TreeNode* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->val << " ";
        inorderTraversal(root->right);
    }
}

// Helper function to print the tree in a visual form
void printTree(TreeNode* root, int depth = 0, char prefix = ' ') {
    if (root != nullptr) {
        printTree(root->right, depth + 1, '/');
        cout << string(4 * depth, ' ') << prefix << "-- " << root->val << endl;
        printTree(root->left, depth + 1, '\\');
    }
}

int main() {
    Solution solution;

    vector<int> inorder = {6, 8, 9, 12, 15, 16, 19};
    vector<int> preorder = {12, 8, 6, 9, 16, 15, 19};

    // Build the tree
    TreeNode* root = solution.buildTree(preorder, inorder);

    // Print the tree in a visual form
    cout << "Visual representation of the constructed BST:\n";
    printTree(root);

    // Verify the tree by performing inorder traversal
    cout << "\nInorder traversal of the constructed BST: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
