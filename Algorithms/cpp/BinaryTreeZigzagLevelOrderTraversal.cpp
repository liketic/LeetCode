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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans = zigzagLevelOrderRecursively(root);
        int lenOfAns = ans.size();

        for (int i = 1; i < lenOfAns; i += 2) {
            for (int l = 0, r = ans[i].size() - 1; l < r; l++, r--) {
                int temp = ans[i][l];
                ans[i][l] = ans[i][r];
                ans[i][r] = temp;
            }
        }
        return ans;
    }
private:
    vector<vector<int>> zigzagLevelOrderRecursively(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }
        vector<vector<int>> sub = mergeResult(zigzagLevelOrderRecursively(root->left),
                                              zigzagLevelOrderRecursively(root->right));
        vector<int> cur;
        cur.push_back(root->val);
        ans.push_back(cur);

        int lenOfSub = sub.size();
        for (int i = 0; i < lenOfSub; i++)
            ans.push_back(sub[i]);
        return ans;
    }

    vector<vector<int>> mergeResult(vector<vector<int>> left,
                                    vector<vector<int>> right) {
        int sizeOfLeft = left.size();
        int sizeOfRight = right.size();

        for (int i = 0; i < sizeOfLeft && i < sizeOfRight; i++) {
            int sizeOfRightI = right[i].size();
            for (int j = 0; j < sizeOfRightI; j++)
                left[i].push_back(right[i][j]);
        }
        for (int i = sizeOfLeft; i < sizeOfRight; i++)
            left.push_back(right[i]);
        return left;
    }
};
