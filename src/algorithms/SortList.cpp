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
    ListNode* sortList(ListNode* head) {
        if (!head) return NULL;
        if (!head->next) return head;

        ListNode* a = head, *b = head->next->next;

        while (a && b) {
            a = a->next;
            b = b->next;
            if (b) b = b->next;
        }
        ListNode* mid = a->next;
        a->next = NULL;

        return mergeList(sortList(head), sortList(mid));
    }

    ListNode* mergeList(ListNode* a, ListNode* b) {
        if (!a) return b;
        if (!b) return a;
        ListNode* ans = NULL, *p = NULL;
        if (a->val <= b->val) {
            ans = a;
            a = a->next;
        } else {
            ans = b;
            b = b->next;
        }
        p = ans;

        while (a && b) {
            if (a->val <= b->val) {
                p->next = a;
                a = a->next;
            } else {
                p->next = b;
                b = b->next;
            }
            p = p->next;
        }
        if (a) p->next = a;
        if (b) p->next = b;
        return ans;
    }
};
