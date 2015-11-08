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
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }

        ListNode* p = head, *q = head->next;
        if (q == NULL) {
            return head;
        }
        ListNode* h = NULL;
        ListNode* temp = NULL;

        while (q) {
            p->next = q->next;
            q->next = p;

            if (h == NULL) {
                h = q;
            } else {
                temp->next = q;
            }
            temp = q;
            p = p->next;
            temp = temp->next;
            if (p) {
                q = p->next;
            } else {
                break;
            }
        }
        return h;
    }
};
