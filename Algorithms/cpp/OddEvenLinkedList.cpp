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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;

        ListNode* odd = head, *even = head->next;
        if (!even) return head;
        ListNode* ptr = even->next, *next, *temp;
        bool isOdd = true;
        even->next = NULL;
        
        while (ptr) {
            next = ptr->next;
            if (isOdd) {
                temp = odd->next;
                odd->next = ptr;
                ptr->next = temp;
                odd = odd->next;
            } else {
                even->next = ptr;
                even = even->next;
                ptr->next = NULL;
            }
            isOdd = !isOdd;
            ptr = next;
        }
        return head;
    }
};
