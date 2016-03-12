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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        int nl = getNodeNumberInSubTree(root->left, p, q);
        int nr = getNodeNumberInSubTree(root->right, p, q);
        if (nl == 1 && nr == 1) return root;
        if (nl == 2) return lowestCommonAncestor(root->left, p, q);
        if (nr == 2) return lowestCommonAncestor(root->right, p, q);
        return root;
    }
private:
    int getNodeNumberInSubTree(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return 0;
        int ans = 0;
        if (root == p || root == q) {
            ans++;
        }
        ans += getNodeNumberInSubTree(root->left, p, q);
        ans += getNodeNumberInSubTree(root->right, p, q);
        return ans;
    }
};
