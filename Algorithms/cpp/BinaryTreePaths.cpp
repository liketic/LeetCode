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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (!root) return ans;

        if (isLeaf(root)) {
            ans.push_back(toString(root->val));
            return ans;
        }
        string rootVal = toString(root->val);

        vector<string> left = binaryTreePaths(root->left);
        addPaths(ans, rootVal, left);

        vector<string> right = binaryTreePaths(root->right);
        addPaths(ans, rootVal, right);

        return ans;
    }
private:
    void addPaths(vector<string>& dest,
                  const string& root,
                  vector<string>& subPaths) {
        int lenOfPaths = subPaths.size();
        for (int i = 0; i < lenOfPaths; i++) {
            dest.push_back(concat(root, subPaths[i]));
        }
    }

    bool isLeaf(TreeNode* root) {
        return root && (!root->left) && (!root->right);
    }

    string concat(const string& a, const string& b) {
        return a + "->" + b;
    }

    string toString(int i) {
        std::stringstream ss;
        ss << i;
        return ss.str();
    }
};
