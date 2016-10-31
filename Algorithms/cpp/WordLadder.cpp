class Solution {
public:
    int ladderLength(const string& beginWord,
                     const string& endWord,
                     unordered_set<string>& wordDict) {
        if (hasAEdge(beginWord, endWord)) {
            return 2;
        }
        int n = wordDict.size();
        int vis[n + 2];
        memset(vis, -1, sizeof(vis));

        string s[n + 2];
        s[0] = beginWord;
        s[n + 1] = endWord;
        int pos = 1;
        for (unordered_set<string>::iterator it = wordDict.begin();
            it != wordDict.end();
            it++) {
            s[pos++] = *it;
        }

        queue<int> q;
        q.push(0);
        vis[0] = 1;

        int ans = 0;

        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (int i = 1; i <= n; i++) {
                if (vis[i] == -1 && hasAEdge(s[t], s[i])) {
                    vis[i] = vis[t] + 1;
                    q.push(i);
                    if (hasAEdge(s[i], endWord)) {
                        ans = vis[i] + 1;
                        break;
                    }
                }
            }
            if (ans) break;
        }
        while (!q.empty()) {
            q.pop();
        }
        return ans;
    }
private:
    // if there is a edge between a and b
    // a and b must has the same length
    bool hasAEdge(const string& a, const string& b) {
        int lenOfA = a.length();
        int t = 0;
        for (int j = 0; j < lenOfA; j++) {
            if (a[j] != b[j]) {
                t++;
                if (t > 1) return false;
            }
        }
        return (t == 1);
    }
};
