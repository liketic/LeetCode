//struct RandomListNode
//{
//    int label;
//    RandomListNode *next, *random;
//    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
//};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL)
            return head;

        RandomListNode* ans = new RandomListNode(head->label);
        RandomListNode* ret = ans;

        while (head) {
            if (head->random) {
                RandomListNode* rand = new RandomListNode(head->random->label);
                ans->random = rand;
            }
            if (head->next) {
                RandomListNode* next = new RandomListNode(head->next->label);
                ans->next = next;
            }
            head = head->next;
            ans = ans->next;
        }
        return ret;
    }
};
