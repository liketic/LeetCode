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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        int len = getLength(head);

        if (k % len == 0) return head;
        int step = len - k % len;

        ListNode* ptr = head;
        while (step > 1) {
            step--;
            ptr = ptr->next;
        }
        ListNode* temp = ptr->next;
        ptr->next = NULL;
        ListNode* last = temp;
        while (last->next) {
            last = last->next;
        }
        last->next = head;
        return temp;
    }
private:
    int getLength(ListNode* head) {
        int t = 0;
        while (head) {
            t++;
            head = head->next;
        }
        return t;
    }
};
