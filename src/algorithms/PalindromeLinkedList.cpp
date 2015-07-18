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
    bool isPalindrome(ListNode* head) {
        if (!head) return true;

        int n = this->lengthOf(head);
        if (n == 1) return true;
        int half = n / 2;
        int step = n - half - 1;
        ListNode* mid = head;

        while (step) {
            mid = mid->next;
            step--;
        }

        ListNode* p = mid;
        ListNode* h = head;
        ListNode* q = reverseList(p->next);

        while (half) {
            half--;
            if (h->val != q->val) return false;
            h = h->next;
            q = q->next;
        }
        return true;
    }
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* p = head;
        ListNode* q = NULL;

        head = head->next;

        while (head) {
            q = head;
            head = head->next;
            q->next = p;
            if (p->next == q) {
                p->next = NULL;
            }
            p = q;
        }
        return p;
    }

    int lengthOf(ListNode* head) {
        int l = 0;
        while (head) {
            ++l;
            head = head->next;
        }
        return l;
    }
};
