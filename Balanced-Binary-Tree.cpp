/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return trav(root);
    }

    bool trav(TreeNode* node) {
        if (node == nullptr) return true;
        if (abs(height(node->left) - height(node->right)) > 1) return false;
        return trav(node->left) && trav(node->right);
    }

    int height(TreeNode* node) {
        if (node == nullptr) return 0;
        return max(height(node->left), height(node->right)) + 1;
    }
};