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
    ListNode* reverseBetween(ListNode* head, int m, int n) {

        ListNode *pre = NULL;
        int cc = 0;

        while (cc < m - 1) {
            cc++;
            if (pre == NULL) pre = head;
            else pre = pre->next;
        }

        ListNode *p = (cc == 0 ? head : pre->next);
        ListNode *q = p->next;
        ListNode *last = p;

        int t = 0;
        while (t < n - m) {
            ListNode *temp = q->next;
            q->next = p;
            p = q;
            q = temp;
            t++;
        }
        last->next = q;

        if (pre != NULL) {
            pre->next = p;
        } else {
            head = p;
        }
        return head;
    }
};
