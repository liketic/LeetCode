class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        map<string, int> dict;
        int n = strs.size();
        bool vis[n];
        memset(vis, 0, sizeof(vis));

        string s;

        for (int i = 0; i < n; i++) {
            s = toOrdered(strs[i]);
            int index = dict[s];
            if (index) {
                vis[index - 1] = vis[i] = true;
                continue;
            }
            dict[s] = i + 1;
        }
        vector<string> ans;
        for (int i = 0; i < n; i++)
            if (vis[i]) ans.push_back(strs[i]);
        return ans;
    }
private:
    string toOrdered(string s) {
        sort(s.begin(), s.end());
        return s;
    }
};
