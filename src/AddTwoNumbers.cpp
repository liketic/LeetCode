struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (NULL == l1 || NULL == l2) {
            return NULL;
        }
        ListNode *ans = l1;
        int last = 0;
        for (;; l1 = l1->next, l2 = l2->next) {
            l1->val += l2->val + last;
            last = l1->val / 10;
            l1->val %= 10;
            if (NULL == l1->next || NULL == l2->next) {
                if (NULL == l1->next) {
                    l1->next = l2->next;
                }
                while (l1->next) {
                    l1 = l1->next;
                    l1->val += last;
                    last = l1->val / 10;
                    l1->val %= 10;
                }
                break;
            }
        }
        if (last) {
            l1->next = new ListNode(last);
        }
        return ans;
    }
};
