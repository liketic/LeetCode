#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {

        ListNode *p = head;
        ListNode *q = head;

        int n = 0, len = this->getLength(p);
        while (n < (len + 1) / 2) {
            if (n + 1 == (len + 1) / 2) {
                ListNode *t = p->next;
                p->next = NULL;
                p = t;
                break;
            }
            p = p->next;
            n++;
        }

        // reverse
        ListNode *h = NULL;
        while (p) {
            ListNode *t = p;
            p = p->next;
            t->next = h;
            h = t;
        }

        // merge two list
        while (q && h) {
            ListNode *temp1 = q->next;
            q->next = h;
            ListNode *temp2 = h->next;
            h->next = temp1;
            q = temp1;
            h = temp2;
        }
    }
private:
    int getLength(ListNode *h) {
        int l = 0;
        while (h) {
            ++l;
            h = h->next;
        }
        return l;
    }
};

/*
int main() {

    return 0;
}*/
