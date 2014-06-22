class Solution {
    public:
        int value(TreeNode *root) {
            return (root == NULL ? 0 : root->val);
        }

        void init(TreeNode *root) {
            if (root == NULL)
                return;
            init(root->left);
            init(root->right);
            int t = max(value(root->left), value(root->right));
            root->val += (t > 0 ? t : 0);
        }

        int maxPathSum(TreeNode *root) {
            init(root);
            queue <TreeNode*> p;
            int ans = -10000000;
            p.push(root);

            while (1) {
                if (p.empty()) {
                    break;
                }
                TreeNode *t = p.front();
                p.pop();
                ans = max(ans, t->val);
                if (value(t->right) > value(t->left)) {
                    ans = max(ans, t->val + value(t->left));
                }
                else {
                    ans = max(ans, t->val + value(t->right));
                }
                if (t->left)
                    p.push(t->left);
                if (t->right)
                    p.push(t->right);
            }
            return ans;
        }
};
