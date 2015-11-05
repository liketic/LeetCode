/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) return "";
        if (isLeaf(root)) return toString(root->val);

        return toString(root->val) + "(" + serialize(root->left) + ")"
            + "(" + serialize(root->right) + ")";
    }

    bool isLeaf(TreeNode* root) {
        return (root != NULL && root->left == NULL && root->right == NULL);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int len = data.length();
        if (len == 0) {
            return NULL;
        }
        int i = 0, v = 0, nn = 1;
        bool hasSub = false;

        for (; i < len; i++) {
            if (data[i] == '(') {
                hasSub = true;
                break;
            }
            if (data[i] == '-') {
                nn *= -1;
            } else {
                v = v * 10 + idx(data[i]);
            }
        }
        v *= nn;
        TreeNode* root = new TreeNode(v);
        if (!hasSub) return root;

        int t = 0, j = i;

        for (; j < len; j++) {
            if (data[j] == '(')t++;
            else if (data[j] == ')') {
                t--;
                if (t == 0)break;
            }
        }
        if (j < len && j - i > 1) {
            TreeNode* l = deserialize(data.substr(i + 1, j - i - 1));
            root->left = l;
        }
        if (j < len && len - j > 3) {
            TreeNode* r = deserialize(data.substr(j + 2, len - j - 3));
            root->right = r;
        }
        return root;
    }

private:
    static int idx(char c) {
        return c - '0';
    }

    static string toString(int v) {
        stringstream ss;
        ss << v;
        return ss.str();
    }
};


// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
