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
    int height(TreeNode *root) {
        if (root == NULL) 
            return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
    
    bool isBalanced(TreeNode *root) {
        if (root == NULL)
            return true;
        int hl = height(root->left);
        int hr = height(root->right);
        if (abs(hl - hr) > 1)
            return false;
        return (isBalanced(root->left) && isBalanced(root->right));
    }
};
