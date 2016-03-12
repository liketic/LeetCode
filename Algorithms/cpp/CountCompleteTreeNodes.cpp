class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        int t = this->getHeight(root);
        int ans = (1 << (t + 1)) - 1;

        while (t) {
            if (noLeafNode(root->right, t - 1)) {
                ans -= (1 << (t - 1));
                root = root->left;
            } else {
                root = root->right;
            }
            t--;
        }
        return ans;
    }
private:
    bool noLeafNode(TreeNode* root, int h) {
        while (h) {
            root = root->left;
            h--;
        }
        return (root == NULL);
    }

    int getHeight(TreeNode* root) {
        int t = 0;
        while (root != NULL) {
            root = root->left;
            t++;
        }
        return t - 1;
    }
};
