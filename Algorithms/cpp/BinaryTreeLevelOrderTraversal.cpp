//struct TreeNode
//{
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
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
        return ans;
    }

private:
    void addBackIfNotNull(queue<TreeNode*>& q, TreeNode* tn) {
        if (tn) {
            q.push(tn);
        }
    }
};
