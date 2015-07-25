/**
 * Definition for a binary tree node.
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> ans = zigzagLevelOrderRecursively(root);
        for (int i = 1; i < ans.size(); i += 2)
        {
            for (int l = 0, r = ans[i].size() - 1; l < r; l++, r--)
            {
                int temp = ans[i][l];
                ans[i][l] = ans[i][r];
                ans[i][r] = temp;
            }
        }
        return ans;
    }
private:
    vector<vector<int>> zigzagLevelOrderRecursively(TreeNode* root)
    {
        vector<vector<int>> ans;
        if (!root)
        {
            return ans;
        }
        vector<vector<int>> sub = mergeResult(zigzagLevelOrderRecursively(root->left),
                                              zigzagLevelOrderRecursively(root->right));
        vector<int> cur;
        cur.push_back(root->val);
        ans.push_back(cur);
        for (int i = 0; i < sub.size(); i++)
            ans.push_back(sub[i]);
        return ans;
    }
    vector<vector<int>> mergeResult(vector<vector<int>> left,
                                    vector<vector<int>> right)
    {
        int n = left.size();
        for (int i = 0; i < n; i++)
        {
            if (i >= right.size()) break;
            for (int j = 0; j < right[i].size(); j++)
                left[i].push_back(right[i][j]);
        }
        for (int i = n; i < right.size(); i++)
            left.push_back(right[i]);
        return left;
    }
};
