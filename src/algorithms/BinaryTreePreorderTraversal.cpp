class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector <int> ans;
        if (root == NULL)
            return ans;

        ans.push_back(root->val);
        vector<int> left = preorderTraversal(root->left);
        pushBackAll(ans, left);
        vector<int> right = preorderTraversal(root->right);
        pushBackAll(ans, right);
        return ans;
    }

private:
    void pushBackAll(vector<int>& dest, vector<int>& src) {
        int sizeOfSrc = src.size();
        for (int i = 0; i < sizeOfSrc; i++) {
            dest.push_back(src[i]);
        }
    }
};
