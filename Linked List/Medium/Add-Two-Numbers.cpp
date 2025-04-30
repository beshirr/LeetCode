/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* n1 = l1;
        ListNode* n2 = l2;
        int c = 0;
        ListNode* head = new ListNode();
        ListNode* tail = head;
        while (n1 != nullptr && n2 != nullptr) {
            int sum = n1->val + n2->val + c;
            c = 0;
            if (sum >= 10) {
                c = 1;
            }
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
            n1 = n1->next;
            n2 = n2->next;
        }
        while (n1 != nullptr) {
            int sum = n1->val + c;
            c = 0;
            if (sum >= 10) {
                c = 1;
            }
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
            n1 = n1->next;
        }
        while (n2 != nullptr) {
            int sum = n2->val + c;
            c = 0;
            if (sum >= 10) {
                c = 1;
            }
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
            n2 = n2->next;
        }
        if (c) {
            tail->next = new ListNode(c);
        }
        return head->next;
    }
};