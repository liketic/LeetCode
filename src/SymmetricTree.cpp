/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (root == NULL)
            return true;
        
        vector <TreeNode*> x, y, temp1, temp2;

        x.push_back(root->left);
        y.push_back(root->right);
        
        while (true) {
            
            int len = x.size();
            if (!len)
                return true;
            for (int i = 0; i < len; i++) {
                if (x[i] == NULL && y[len - i - 1] == NULL)
                    continue;
                if (x[i] == NULL || y[len - i - 1] == NULL)
                    return false;
                if (x[i]->val != y[len - i - 1]->val)
                    return false;
            }
            for (int i = 0; i < len; ++i) {
                if (x[i]) {
                    temp1.push_back(x[i]->left);
                    temp1.push_back(x[i]->right);
                }
                if (y[i]) {
                    temp2.push_back(y[i]->left);
                    temp2.push_back(y[i]->right);
                }
            }
            x = temp1;
            y = temp2;
            temp1.clear();
            temp2.clear();
        }
        return true;
    }
};
