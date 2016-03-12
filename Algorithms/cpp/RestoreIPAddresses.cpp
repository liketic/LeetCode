class Solution {
public:
    vector<string> restoreIpAddresses(const string& s) {
        return dfs(s, 0, 4);
    }

    bool isOk(int v) {
        return v >= 0 && v <= 255;
    }

    vector<string> dfs(const string& s, int pos, int t) {
        vector<string> ans;

        if (t == 0) {
            if (pos >= s.length()) {
                ans.push_back("");
            }
            return ans;
        }

        int len = s.length();
        int x = 0;

        for (int i = pos; i < pos + 3 && i < len; i++) {
            if (i > pos && s[pos] == '0') break;
            x = x * 10 + (s[i] - '0');
            if (isOk(x)) {
                vector<string> temp = dfs(s, i + 1, t - 1);
                int lenOfTemp = temp.size();
                if (lenOfTemp > 0) {
                    string prefix = s.substr(pos, i - pos + 1);

                    for (int j = 0; j < lenOfTemp; j++) {
                        ans.push_back(addAtFront(prefix, temp[j]));
                    }
                }
            }
        }
        return ans;
    }

    string addAtFront(const string& a, const string& b) {
        if (b == "") return a;
        return a + "." + b;
    }
};
