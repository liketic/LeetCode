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
    ListNode* reverseList(ListNode* head) {
        ListNode* ptr = head;
        ListNode* ans = NULL;
        ListNode* temp = NULL;
        while (ptr) {
            temp = new ListNode(ptr->val);
            temp->next = ans;
            ans = temp;
            ptr = ptr->next;
        }
        return ans;
    }
};
