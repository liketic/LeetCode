class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
    		int n = s.size();
    		int q[n + 1];
    		memset(q, 0, sizeof(q));
    		q[0] = 1;

    		unordered_set<string>::iterator it;
    		string t;

    		for (int i = 1; i <= n; i++) {
    			for (it = dict.begin(); it != dict.end(); ++it) {

    				t = *it;
    				int j = t.size();
    				if (i < j || !q[i - j]) continue;

    				bool flag = true;
    				for (int k = j; k >= 1; k--) {
    					if (s[i - j + k - 1] != t[k - 1]) {
    						flag = false;
    						break;
    					}
    				}
    				if (flag) {
    					q[i] = 1;
    				}
    			}
    		}
    		return (q[n] == 1);
    }
};
