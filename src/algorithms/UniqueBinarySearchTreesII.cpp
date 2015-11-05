/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return generateTreeOnInterval(1, n);
    }

    vector<TreeNode*> generateTreeOnInterval(int l, int r) {
        vector<TreeNode*> v;
        if (l > r) {
            v.push_back(NULL);
            return v;
        }
        if (l == r) {
            TreeNode* root = new TreeNode(l);
            v.push_back(root);
            return v;
        }
        vector<TreeNode*> lt;
        vector<TreeNode*> rt;

        for (int i = l; i <= r; i++) {
            lt = generateTreeOnInterval(l, i - 1);
            rt = generateTreeOnInterval(i + 1, r);
            vector<TreeNode*> t = mergeLeftAndRight(i, lt, rt);
            int lenOf = t.size();
            for (int j = 0; j < lenOf; j++) {
                v.push_back(t[j]);
            }
        }
        return v;
    }

    vector<TreeNode*> mergeLeftAndRight(int v, vector<TreeNode*> lt, vector<TreeNode*> rt) {
        int lenOfL = lt.size();
        int lenOfR = rt.size();

        if (lenOfL == 0) {
            for (int i = 0; i < lenOfR; i++) {
                TreeNode* tt = new TreeNode(v);
                tt->right = rt[i];
                rt[i] = tt;
            }
            return rt;
        }
        if (lenOfR == 0) {
            for (int i = 0; i < lenOfL; i++) {
                TreeNode* tt = new TreeNode(v);
                tt->left = lt[i];
                lt[i] = tt;
            }
            return lt;
        }
        vector<TreeNode*> ret;

        for (int i = 0; i < lenOfL; i++) {
            for (int j = 0; j < lenOfR; j++) {
                TreeNode* tt = new TreeNode(v);
                tt->left = lt[i];
                tt->right = rt[j];
                ret.push_back(tt);
            }
        }
        return ret;
    }
};
