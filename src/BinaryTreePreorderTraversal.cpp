class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector <int> x;

        if (root == NULL)
            return x;

        x.push_back(root->val);
        vector <int> a = preorderTraversal(root->left);
        vector <int> b  = preorderTraversal(root->right);

        for (int i = 0; i < a.size(); i++)
            x.push_back(a[i]);

        for (int i = 0; i < b.size(); i++)
            x.push_back(b[i]);

        return x;
    }
};
