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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return NULL;
        return buildTree(nums, 0, n - 1);
    }
private:
    TreeNode* buildTree(vector<int>& v, int l, int r) {
        if (l > r) return NULL;
        int mid = (l + r) / 2;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = buildTree(v, l, mid - 1);
        root->right = buildTree(v, mid + 1, r);
        return root;
    }
};
