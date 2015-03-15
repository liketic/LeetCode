
//struct TreeNode
//{
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> x;
        if (root == NULL)
            return x;

        vector<int> a = inorderTraversal(root->left);
        vector<int> b = inorderTraversal(root->right);
        for (int i = 0; i < a.size(); i++)
            x.push_back(a[i]);
        x.push_back(root->val);
        for (int i = 0; i < b.size(); i++)
            x.push_back(b[i]);
        return x;
    }
};
