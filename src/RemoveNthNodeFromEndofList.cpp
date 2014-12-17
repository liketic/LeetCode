//#include <iostream>
//
//using namespace std;
//
//// Definition for singly-linked list.
//struct ListNode
//{
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == NULL)
        {
            return head;
        }
        n--;
        ListNode *p = head, *q = head, *s;
        while (n)
        {
            n--;
            q = q->next;
        }
        while (q->next)
        {
            s = p;
            p = p->next;
            q = q->next;
        }

        if (p == head)
        {
            head = head->next;
        }
        else
        {
            s->next = p->next;
        }
        delete p;
        return head;
    }
};
//
//int main()
//{
//    Solution s;
//    ListNode *h = new ListNode(1);
//    ListNode *p = h;
//    ListNode *q = new ListNode(2);
//    p->next = q;
//    p = p->next;
//    q = new ListNode(3);
//    p->next = q;
//    p = p->next;
//    q = new ListNode(4);
//    p->next = q;
//    p = p->next;
//    q = new ListNode(5);
//    p->next = q;
//    p = p->next;
//
//    h = s.removeNthFromEnd(h, 5);
//
//    while (h)
//    {
//        cout << h->val << endl;
//        h = h->next;
//    }
//
//    return 0;
//}
