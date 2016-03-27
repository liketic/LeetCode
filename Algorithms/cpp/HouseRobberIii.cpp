// Source : https://leetcode.com/problems/house-robber-iii/
// Author : Ke Li
// Date   : 2016-03-27

/***************************************************************************************
 *
 * The thief has found himself a new place for his thievery again. There is only one
 * entrance to this area, called the "root." Besides the root, each house has one and
 * only one parent house. After a tour, the smart thief realized that "all houses in
 * this place forms a binary tree". It will automatically contact the police if two
 * directly-linked houses were broken into on the same night.
 *
 * Determine the maximum amount of money the thief can rob tonight without alerting the
 * police.
 *
 * Example 1:
 *
 *      3
 *     / \
 *    2   3
 *     \   \
 *      3   1
 *
 * Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
 *
 * Example 2:
 *
 *      3
 *     / \
 *    4   5
 *   / \   \
 *  1   3   1
 *
 * Maximum amount of money the thief can rob = 4 + 5 = 9.
 *
 * Credits:Special thanks to @dietpepsi for adding this problem and creating all test
 * cases.
 ***************************************************************************************/

/**
 * Definition for a binary tree node.
 **/
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};

class Solution {
public:
    int rob(TreeNode* root) {
        return max(rob(root, true), rob(root, false));
    }
    
private:
    
    map<TreeNode*, int> robCache;
    map<TreeNode*, int> notRobCache;
    
    int rob(TreeNode* root, bool robRoot) {
        if (!root) return 0;
        map<TreeNode*, int>::iterator it;
        
        // rob root node
        if (robRoot) {
            it = robCache.find(root);
            if (it != robCache.end()) {
                return it->second;
            }
            int ret = root->val + rob(root->left, false) + rob(root->right, false);
            robCache[root] = ret;
            return ret;
        }
        // not rob root node
        it = notRobCache.find(root);
        if (it != notRobCache.end()) {
            return it->second;
        }
        int ret = max(rob(root->left, true), rob(root->left, false)) + max(rob(root->right, true), rob(root->right, false));
        notRobCache[root] = ret;
        return ret;
    }
};




