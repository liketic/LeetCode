class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        ans.push_back(root->val);
        vector<int> l = rightSideView(root->left);
        vector<int> r = rightSideView(root->right);
        for (int i = 0; i < r.size(); i++)
            ans.push_back(r[i]);
        if (l.size() > r.size()) {
            for (int i = r.size(); i < l.size(); i++) {
                ans.push_back(l[i]);
            }
        }
        return ans;
    }
};
