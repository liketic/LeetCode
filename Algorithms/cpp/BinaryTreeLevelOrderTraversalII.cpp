class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector <vector<int> > ans;
        if (root == NULL)
            return ans;

        queue<TreeNode*> levelQueue;
        levelQueue.push(root);

        while (!levelQueue.empty()) {
            int sizeOfQueue = levelQueue.size();
            vector<int> levelVals;

            for (int i = 0; i < sizeOfQueue; i++) {
                TreeNode* node = levelQueue.front();
                levelQueue.pop();
                levelVals.push_back(node->val);
                addBackIfNotNull(levelQueue, node->left);
                addBackIfNotNull(levelQueue, node->right);
            }
            ans.push_back(levelVals);
        }
        reverseVector(ans);
        return ans;
    }

private:
    void addBackIfNotNull(queue<TreeNode*>& q, TreeNode* tn) {
        if (tn) {
            q.push(tn);
        }
    }
    void reverseVector(vector<vector<int>>& v) {
        int len = v.size();
        for (int i = 0, j = len - 1; i < j; i++, j--) {
            vector <int> t = v[i];
            v[i] = v[j];
            v[j] = t;
        }
    }
};
