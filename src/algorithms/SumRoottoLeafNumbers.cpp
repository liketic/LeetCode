/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    int tot(TreeNode* root, int t)
    {
        if (root == NULL)
            return t;
        t = t * 10 + root->val;
        if (root->left == NULL && root->right == NULL)
            return t;
        int ans = 0;
        if (root->left)
        {
            ans += tot(root->left, t);
        }
        if (root->right)
        {
            ans += tot(root->right, t);
        }
        return ans;
    }

    int sumNumbers(TreeNode *root)
    {
        return tot(root, 0);
    }
};
