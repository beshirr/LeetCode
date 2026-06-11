1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11/**
12 * Definition for a binary tree node.
13 * struct TreeNode {
14 *     int val;
15 *     TreeNode *left;
16 *     TreeNode *right;
17 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
18 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
19 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
20 * };
21 */
22class Solution {
23public:
24    TreeNode* sortedListToBST(ListNode* head) {
25        if (head == nullptr) return nullptr;
26        return insert(head);
27    }
28
29    TreeNode* insert(ListNode* head) {
30        if (head == nullptr) return nullptr;
31        if (head->next == nullptr) return new TreeNode(head->val);
32        ListNode* slow = head, *s_prev = head, *fast = head;
33
34        while (fast && fast->next) {
35            s_prev = slow;
36            slow = slow->next;
37            fast = fast->next->next;
38        } // mid list is slow pointer
39
40        TreeNode* root = new TreeNode(slow->val);
41        s_prev->next = nullptr;
42
43        root->left = insert(head);
44        root->right = insert(slow->next);
45
46        return root;
47    }
48};