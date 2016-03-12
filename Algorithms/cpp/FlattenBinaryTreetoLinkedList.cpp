class Solution {
public:
    void flatten(TreeNode *root) {
        if (root == NULL)
            return;
        TreeNode *ri = root->right;
        root->right = NULL;

        if (root->left) {
            flatten(root->left);
            root->right = root->left;
        }

        if (ri) {
            flatten(ri);
            TreeNode *t = root;

            while (t->right) {
                t = t->right;
            }
            t->right = ri;
        }
        root->left = NULL;
    }
};
