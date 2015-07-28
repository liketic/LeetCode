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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size() - 1,
                         inorder, 0, inorder.size() - 1);
    }
private:
    TreeNode* buildTree(vector<int>& preorder, int lp, int rp,
                        vector<int>& inorder, int li, int ri) {
        if (li > ri) return NULL;
        int rootVal = preorder[lp];
        TreeNode* root = new TreeNode(rootVal);

        int count = 0;
        for (int i = li; i <= ri; i++) {
            if (inorder[i] == rootVal) {
                break;
            }
            count++;
        }
        root->left = buildTree(preorder, lp + 1, lp + count,
                               inorder, li, li + count - 1);
        root->right = buildTree(preorder, lp + count + 1, rp,
                                inorder, li + count + 1, ri);
    }
};
