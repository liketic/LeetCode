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
    ListNode* partition(ListNode* head, int x) {
        if (!head) return NULL;
        ListNode* p = head;

        if (p->val >= x) {
            ListNode* q = p;
            while (q->next && q->next->val >= x) {
                q = q->next;
            }
            if (!q->next) return head;
            ListNode* temp = q->next;
            q->next = temp->next;
            temp->next = p;
            head = temp;
        }
        p = head;

        while (p) {
            if (p->next && p->next->val >= x) {
                ListNode* q = p;
                while (q->next && q->next->val >= x) {
                    q = q->next;
                }
                if (!q->next) return head;
                ListNode* temp1 = q->next;
                q->next = temp1->next;
                ListNode* temp2 = p->next;
                p->next = temp1;
                temp1->next = temp2;
            }
            p = p->next;
        }
        return head;
    }
};

