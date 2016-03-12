/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        connectTwoNode(root->left, root->right);
    }
private:
    void connectTwoNode(TreeLinkNode *left, TreeLinkNode *right) {
        if (left == NULL || right == NULL)
            return;
        left->next = right;
        connectTwoNode(left->left, left->right);
        connectTwoNode(left->right, right->left);
        connectTwoNode(right->left, right->right);
    }
};
