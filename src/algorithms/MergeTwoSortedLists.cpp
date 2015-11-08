
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        ListNode* ans = l1, *q = NULL;

        while (l1 && l2) {
            if (l1->val > l2->val) {
                ListNode* temp = l2;
                l2 = l2->next;
                temp->next = l1;
                if (q) {
                    q->next = temp;
                    q = q->next;
                } else {
                    q = temp;
                    ans = temp;
                }
            } else {
                q = l1;
                l1 = l1->next;
            }
        }
        if (l2)q->next = l2;

        return ans;
    }
};
