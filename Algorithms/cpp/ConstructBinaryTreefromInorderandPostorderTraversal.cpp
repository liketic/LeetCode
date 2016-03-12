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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size() - 1,
                         postorder, 0, postorder.size() - 1);
    }
private:
    TreeNode* buildTree(vector<int>& inorder, int li, int ri,
                        vector<int>& postorder, int lp, int rp) {
        if (li > ri) return NULL;
        int rootVal = postorder[rp];
        TreeNode* root = new TreeNode(rootVal);

        int count = 0;
        for (int i = li; i <= ri; i++) {
            if (inorder[i] == rootVal) {
                break;
            }
            count++;
        }
        root->left = buildTree(inorder, li, li + count - 1,
                               postorder, lp, lp + count - 1);
        root->right = buildTree(inorder, li + count + 1, ri,
                                postorder, lp + count, rp - 1);
    }
};
