
class Solution
{
public:
    ListNode *insertionSortList(ListNode *head)
    {

        if (head == NULL)
            return head;

        ListNode *h = head;

        while (h)
        {

            ListNode *q = h->next;

            if (q == NULL)
                break;

            if (q->val < h->val)
            {
                if (q->val < head->val)
                {
                    h->next = q->next;
                    q->next = head;
                    head = q;
                }
                else
                {
                    ListNode* x = head, *y = head->next;
                    while (y->val < q->val)
                    {
                        x = y;
                        y = y->next;
                    }
                    h->next = q->next;
                    q->next = y;
                    x->next = q;
                }
            }
            else
            {
                h = h->next;
            }
        }

        return head;
    }
};
