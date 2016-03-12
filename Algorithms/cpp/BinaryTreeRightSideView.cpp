class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        ans.push_back(root->val);
        vector<int> left = rightSideView(root->left);
        vector<int> right = rightSideView(root->right);
        int lenOfLeft = left.size();
        int lenOfRight = right.size();

        for (int i = 0; i < lenOfRight; i++)
            ans.push_back(right[i]);

        if (lenOfLeft > lenOfRight) {
            for (int i = lenOfRight; i < lenOfLeft; i++) {
                ans.push_back(left[i]);
            }
        }
        return ans;
    }
};
