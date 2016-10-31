//struct TreeNode
//{
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};

class Solution {
private:
    int check(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int l = check(root->left);
        int r = check(root->right);
        if (l == -1 || r == -1 || abs(l - r) > 1) {
            return -1;
        }
        return max(l, r) + 1;
    }
public:
    // check if the tree which root node is 'root' is balanced
    bool isBalanced(TreeNode *root) {
        return check(root) >= 0;
    }
};
