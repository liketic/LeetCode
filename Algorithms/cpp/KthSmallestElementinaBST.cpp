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
    int kthSmallest(TreeNode* root, int k) {
        int sizeOfLeft = sizeOf(root->left);
        if (sizeOfLeft >= k) {
            return kthSmallest(root->left, k);
        } else if (sizeOfLeft == k - 1) {
            return root->val;
        } else {
            return kthSmallest(root->right, k - sizeOfLeft - 1);
        }

    }
private:
    int sizeOf(TreeNode* root) {
        if (!root) return 0;
        return (1 + sizeOf(root->left) + sizeOf(root->right));
    }
};
