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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return NULL;
        map<int, int> dict;
        ListNode* ptr = head;
        while (ptr) {
            dict[ptr->val] += 1;
            ptr = ptr->next;
        }
        ptr = head;

        // delete head node if necessary
        while (ptr && dict[ptr->val] > 1) {
            ListNode* toDelete = ptr;
            ptr = ptr->next;
            delete toDelete;
            toDelete = NULL;
        }

        head = ptr;
        if (!head) return NULL;

        while (ptr->next) {
            int val = ptr->next->val;
            if (dict[val] > 1) {
                ListNode* ptrNext = ptr->next;
                ptr->next = ptrNext->next;
                delete ptrNext;
                ptrNext = NULL;
                continue;
            }
            ptr = ptr->next;
        }
        return head;
    }
};
