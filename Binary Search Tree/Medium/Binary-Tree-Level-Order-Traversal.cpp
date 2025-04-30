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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }

        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int levelSize = que.size();
            vector<int> currentLevel;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* current = que.front();
                que.pop();

                currentLevel.push_back(current->val);
                if (current->left != nullptr) {
                    que.push(current->left);
                }
                if (current->right != nullptr) {
                    que.push(current->right);
                }
            }
            result.push_back(currentLevel);
        }

        return result;
    }
};