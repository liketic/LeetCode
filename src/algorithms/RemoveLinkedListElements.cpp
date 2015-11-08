/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) return head;
        ListNode *p = head;
        while (head && head->val == val) {
            head = head->next;
            delete p;
            p = head;
        }

        while (p) {
            if (p->next != NULL && p->next->val == val) {
                ListNode *q = p->next;
                p->next = p->next->next;
                delete q;
                q = NULL;
            } else {
                p = p->next;
            }
        }
        return head;
    }
};
