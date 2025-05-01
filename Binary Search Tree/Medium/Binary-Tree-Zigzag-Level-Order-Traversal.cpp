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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        deque<TreeNode*> q;
        q.push_front(root);

        bool right = false;
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;
            for (int i = 0; i < levelSize; i++) {
                TreeNode* current = nullptr;
                if (!right) {
                    current = q.front();
                    q.pop_front();

                    if (current->left != nullptr) {
                        q.push_back(current->left);
                    }
                    if (current->right != nullptr) {
                        q.push_back(current->right);
                    }

                } else {
                    current = q.back();
                    q.pop_back();

                    if (current->right != nullptr) {
                        q.push_front(current->right);
                    }
                    if (current->left != nullptr) {
                        q.push_front(current->left);
                    }
                }
                currentLevel.push_back(current->val);
            }
            result.push_back(currentLevel);
            right = !right;
        }

        return result;
    }
};