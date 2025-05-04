/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode* xx = find(root, x);
        TreeNode* yy = find(root, y);
        return (level(root, xx, 0) == level(root, yy, 0) &&
                !siblings(root, xx, yy));
    }

    TreeNode* find(TreeNode* root, int val) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val == val) {
            return root;
        }

        TreeNode* node = find(root->left, val);
        if (node != nullptr)
            return node;
        return find(root->right, val);
    }

    int level(TreeNode* root, TreeNode* x, int lev) {
        if (root == nullptr)
            return 0;
        if (root == x) {
            return lev;
        }
        int l = level(root->left, x, lev + 1);
        if (l != 0)
            return l;
        return level(root->right, x, lev + 1);
    }

    bool siblings(TreeNode* root, TreeNode* x, TreeNode* y) {
        if (root == nullptr) {
            return false;
        }
        return ((root->left == x && root->right == y) ||
                (root->left == y && root->right == x) ||
                siblings(root->left, x, y) || siblings(root->right, x, y));
    }
};