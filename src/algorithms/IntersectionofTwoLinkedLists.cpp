//#include <iostream>
//
//using namespace std;
//
//
////Definition for singly-linked list.
//struct ListNode
//{
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int lA = 0, lB = 0;
        ListNode* p = headA;
        for (; p; p = p->next) {
            lA++;
        }
        ListNode *q = headB;
        for (; q; q = q->next) {
            lB++;
        }

        p = headA;
        q = headB;
        while (lA > lB) {
            lA--;
            p = p->next;
        }
        while (lB > lA) {
            lB--;
            q = q->next;
        }
        while (lA) {
            if (p == q) {
                return q;
            }
            lA--;
            p = p->next;
            q = q->next;
        }
        return NULL;
    }
};


//int main()
//{
//    ListNode *p = new ListNode(1);
//    ListNode *q = p;
//
//    Solution s;
//
//    ListNode *ret = s.getIntersectionNode(p, q);
//
//    cout << (ret == NULL) << endl;
//
//    return 0;
//}
