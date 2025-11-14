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
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;

        int l = getLeftH(root); int r = getRightH(root);

        if (l == r) return (1 << l) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }

    int getLeftH(TreeNode* node) {
        if (node == nullptr) return 0;
        return 1 + getLeftH(node->left);
    }

    int getRightH(TreeNode* node) {
        if (node == nullptr) return 0;
        return 1 + getRightH(node->right);
    }    
};