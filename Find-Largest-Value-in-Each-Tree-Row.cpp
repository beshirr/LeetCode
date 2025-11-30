1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    vector<int> largestValues(TreeNode* root) {
15        if (root == nullptr) return {};
16        queue<TreeNode*> q;
17        vector<int> r;
18
19        q.push(root);
20
21        while (!q.empty()) {
22            int len = q.size();
23
24            int maxVal = q.front()->val;
25            for (int i = 0; i < len; i++) {
26                TreeNode *node = q.front();
27                maxVal = max(maxVal, node->val);
28                q.pop();
29
30                if (node->left != nullptr)
31                    q.push(node->left);
32
33                if (node->right != nullptr)
34                    q.push(node->right);
35            }
36            r.push_back(maxVal);
37        }
38        return r;
39    }
40};