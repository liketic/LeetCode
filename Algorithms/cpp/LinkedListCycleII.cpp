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
    ListNode *detectCycle(ListNode *head) {
        if (!head) return NULL;
        ListNode* ptr = head;
        ListNode* p = head;
        ListNode* q = head;

        while (p && q) {
            p = p->next;
            if (!q->next) return NULL;
            q = q->next->next;
            if (!p || !q) {
                return NULL;
            }
            if (p == q) break;
        }
        while (true) {
            ListNode* t = p;
            while (true) {
                if (t == ptr) return ptr;
                t = t->next;
                if (t == p)break;
            }
            ptr = ptr->next;
        }
        // unreachable
        return NULL;
    }
};
