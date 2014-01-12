class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> x;
        
        if (root == NULL)
            return x;
        vector <int> a = postorderTraversal(root->left);
        vector <int> b = postorderTraversal(root->right);
        
        for (int i = 0; i < a.size(); i++)
            x.push_back(a[i]);
        for (int i = 0; i < b.size(); i++)
            x.push_back(b[i]);
        x.push_back(root->val);
        
        return x;
    }
};
