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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> indexes;
        for (int i = 0; i < inorder.size(); i++) {
            indexes[inorder[i]] = i;
        }

        return build(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1, indexes);
    }

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int iStart, int iEnd, 
                    int pStart, int pEnd, unordered_map<int, int>& index) {

        if (iStart > iEnd || pStart > pEnd) return nullptr;

        int r = postorder[pEnd];
        TreeNode* root = new TreeNode(r);
        int ri = index[r];
        int s = ri - iStart;
        root->left = build(inorder, postorder, iStart, ri-1, pStart, pStart + s - 1, index);
        root->right = build(inorder, postorder, ri + 1, iEnd, pStart + s, pEnd - 1, index);
        return root;
    }
};