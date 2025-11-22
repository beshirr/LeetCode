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
    TreeNode* f = nullptr;
    TreeNode* s = nullptr;
    TreeNode* p = nullptr;
    void recoverTree(TreeNode* root) {

        trav(root);
        swap(f->val, s->val);
    }

    void trav(TreeNode* node) {
        if (node == nullptr) return;

        trav(node->left);
        
        if (p && p->val > node->val) {
            if (!f) f = p;
            s = node;
        }
        p = node;
        trav(node->right);
    }
};