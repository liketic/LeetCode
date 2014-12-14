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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector< vector<int> > x;
        if (root == NULL)
            return x;
        if (sum == root->val && root->left == NULL && root->right == NULL)
        {
            vector<int> ans;
            ans.push_back(root->val);
            x.push_back(ans);
            return x;
        }
        else {
            vector< vector<int> > a = pathSum(root->left, sum - root->val);
            vector< vector<int> > b = pathSum(root->right, sum - root->val);
            int l = b.size();
            for (int i = 0; i < l; i++)
                a.push_back(b[i]);
            l = a.size();
            for (int i = 0; i < l; i++) {
                vector<int> y;
                y.push_back(root->val);
                int l = a[i].size();
                for (int j = 0; j < l; j++)
                    y.push_back(a[i][j]);
                x.push_back(y);
            }
            return x;
        }
    }
};
