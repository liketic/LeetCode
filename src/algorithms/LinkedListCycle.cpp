class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode *p = head, *q = head;

        while (p && q)
        {
            p = p->next;
            q = q->next;
            if (q == NULL)
                return false;
            q = q->next;
            if (p && q && (p == q))
                return true;
        }
        return false;

    }
};
