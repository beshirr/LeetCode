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
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return mind;
    }

    void dfs(TreeNode* root) {
        if (root == nullptr) return;

        dfs(root->left);
        if (p) mind = min(mind, root->val - p->val);
        p = root;
        dfs(root->right);
    }
    int mind = INT_MAX;
    TreeNode* p = nullptr;
};