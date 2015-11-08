
//struct TreeNode
//{
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> ans;
        if (root == NULL)
            return ans;
        // add left nodes
        vector<int> leftAns = inorderTraversal(root->left);
        pushBackAll(ans, leftAns);
        // add current node
        ans.push_back(root->val);
        // add right nodes
        vector<int> rightAns = inorderTraversal(root->right);
        pushBackAll(ans, rightAns);

        return ans;
    }

private:
    void pushBackAll(vector<int>& dest, vector<int>& src) {
        int lenOfSrc = src.size();
        for (int i = 0; i < lenOfSrc; i++) {
            dest.push_back(src[i]);
        }
    }
};
