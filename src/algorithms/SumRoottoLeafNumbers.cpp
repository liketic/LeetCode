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
private:
    int calcuate(TreeNode* root, int t) {
        if (root == NULL)
            return t;
        t = t * 10 + root->val;
        if (root->left == NULL && root->right == NULL)
            return t;
        int ans = 0;
        if (root->left) {
            ans += calcuate(root->left, t);
        }
        if (root->right) {
            ans += calcuate(root->right, t);
        }
        return ans;
    }

public:
    int sumNumbers(TreeNode *root) {
        return calcuate(root, 0);
    }
};
