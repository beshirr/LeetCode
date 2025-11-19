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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> v; vector<int> sv;
        int cs = 0;
        trav(root, targetSum, v, sv, cs);
        return v;
    }

    void trav(TreeNode* node, int t, vector<vector<int>>& v, vector<int>& sv, int cs) {
        if (node == nullptr) return;

        sv.push_back(node->val);
        cs += node->val;
        if (!node->left && !node->right) {
            if (cs == t) {
                v.push_back(sv);
            }
        }
        trav(node->left, t, v, sv, cs);
        trav(node->right, t, v, sv, cs);
        sv.pop_back();
    }
};