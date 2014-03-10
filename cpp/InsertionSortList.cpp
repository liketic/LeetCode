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
    ListNode *insertionSortList(ListNode *head) {

        if (head == NULL)
            return head;

        ListNode *h = head;

        while (h) {

            ListNode *q = h->next;

            if (q == NULL)
                break;

            if (q->val < h->val) {

                   // cout << "q1: "<<q->val << endl;

                if (q->val < head->val) {
                    h->next = q->next;
                    q->next = head;
                    head = q;
                    //cout << "q2: "<<q->val << endl;
                }
                else {
                    ListNode* x = head, *y = head->next;
                    while (y->val < q->val) {
                        x = y;
                        y = y->next;
                    }
                    h->next = q->next;
                    q->next = y;
                    x->next = q;
                }
            } else {
                h = h->next;
            }
        }

        return head;
    }
};
