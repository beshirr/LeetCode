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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        TreeNode* root = nullptr;
        insert(root, nums, start, end);
        return root;
    }

    void insert(TreeNode*& node, vector<int>& nums, int start, int end) {
        if (start > end) {
            return;
        }
        int mid = start + (end - start) / 2;
        node = new TreeNode(nums[mid]);
        insert(node->left, nums, start, mid - 1);
        insert(node->right, nums, mid + 1, end);
    }
    
};