/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int maxNode(TreeNode* root) {
        int val = root->val;
        if (root->left)
            val = max(val, maxNode(root->left));
        if (root->right)
            val = max(val, maxNode(root->right));
        return val;
    }
    int minNode(TreeNode* root) {
        int val = root->val;
        if (root->left)
            val = min(val, maxNode(root->left));
        if (root->right)
            val = min(val, maxNode(root->right));
        return val;
    }
    bool isValidBST(TreeNode *root) {
        if (root == NULL)return true;
        if (root->left == NULL && root->right == NULL)
            return true;
        if (root->right == NULL) {
            return (root->val > maxNode(root->left) && isValidBST(root->left));
        }
        if (root->left == NULL) {
            return (root->val < minNode(root->right) && isValidBST(root->right));
        }
        return (isValidBST(root->left) && isValidBST(root->right)
                && root->val < minNode(root->right)
                && root->val > maxNode(root->left));
    }
};
