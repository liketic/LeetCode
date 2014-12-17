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
    bool hasPathSum(TreeNode *root, int sum)
    {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (root == NULL)
            return 0;
        if (root->val == sum && root->left == NULL && root->right == NULL)
            return 1;
        return hasPathSum(root->left, sum - root->val) + hasPathSum(root->right, sum - root->val);
    }
};
