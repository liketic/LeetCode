/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return buildTree(head, getLength(head));
    }
private:
    int getLength(ListNode* head) {
        int t = 0;
        while (head) {
            head = head->next;
            t++;
        }
        return t;
    }
    TreeNode* buildTree(ListNode* head, int length) {
        if (length == 0) return NULL;
        int mid = (length - 1) / 2;
        ListNode* node = head;
        while (mid--) {
            node = node->next;
        }
        TreeNode* root = new TreeNode(node->val);
        root->left = buildTree(head, (length - 1) / 2);
        root->right = buildTree(node->next, length - 1 - (length - 1) / 2);
    }
};
