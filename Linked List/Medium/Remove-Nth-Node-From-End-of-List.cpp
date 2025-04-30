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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = getSize(head);
        
        if (sz == n) {
            ListNode* temp = head;
            head = head->next;
            return head;
        }

        int index = sz - n;
        ListNode* prev = head;

        for (int i = 0; i < index - 1; i++) {
            prev = prev->next;
        }

        prev->next = prev->next->next;

        return head;
    }

    int getSize(ListNode* head) {
        int size = 0;
        ListNode* node = head;
        while (node != nullptr) {
            size++;
            node = node->next;
        }
        return size;
    }
};
