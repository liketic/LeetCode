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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (!root) return ans;

        if (!root->left && !root->right) {
            ans.push_back(this->toStr(root->val));
            return ans;
        }
        vector<string> left = binaryTreePaths(root->left);
        for (int i = 0; i < left.size(); i++) {
            ans.push_back(this->toStr(root->val) + "->" + left[i]);
        }
        vector<string> right = binaryTreePaths(root->right);
        for (int i = 0; i < right.size(); i++) {
            ans.push_back(this->toStr(root->val) + "->" + right[i]);
        }
        return ans;
    }
private:
    string toStr(int i) {
        std::stringstream str1;
        str1 << i;
        return str1.str();
    }
};
