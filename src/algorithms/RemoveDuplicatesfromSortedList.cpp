class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *p = head, *q = head->next;
        p->next = NULL;

        while (q)
        {

            if (q->val > p->val)
            {
                p->next = q;
                q = q->next;
                p = p->next;
                p->next = NULL;
            }
            else
            {
                ListNode* temp = q;
                q = q->next;
                delete temp;
            }
        }
        return head;

    }
};
