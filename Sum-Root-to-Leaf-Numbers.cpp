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
    int sumNumbers(TreeNode* root) {
        int s = 0;
        vector<int> v;
        trav(root, v, s);
        return s;
    }

    void trav(TreeNode* node, vector<int>& v, int& s) {
        if (node == nullptr) return;

        v.push_back(node->val);
        if (!node->left && !node->right) {
            calculateSum(v, s);
        }
        trav(node->left, v, s);
        trav(node->right, v, s);
        v.pop_back();
    }

    void calculateSum(vector<int>& v, int& s) {
        int i, j;
        for (i = v.size()-1, j = 0; i >= 0 && j < v.size(); i--, j++) {
            s += v[i] * pow(10, j);
        }
    }
};