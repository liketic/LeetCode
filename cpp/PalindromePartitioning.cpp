class Solution {
    public:
        vector< vector<string> > partition(string s) {

            vector < vector <string> > ans;

            if (s == "") {
                return ans;
            }

            if (s.size() == 1) {
                vector <string> tem;
                tem.push_back(s);
                ans.push_back(tem);
                return ans;
            }

            int n = s.size();

            for (int i = 0; i < n; i++) {
                bool ok = true;
                for (int k1 = 0, k2 = i; k1 < k2; k1++, k2--)
                    if (s[k1] != s[k2])
                    {
                        ok = false;
                        break;
                    }
                if (ok) {
                    string t = s.substr(0, i + 1);
                    if (t == s) {
                        vector <string> x;
                        x.push_back(t);
                        ans.push_back(x);
                    } else {
                        vector< vector<string> > temp = partition(s.substr(i + 1, s.length() - i - 1));
                        int siz = temp.size();
                        for (int k = 0; k < siz; k++) {
                            temp[k].insert(temp[k].begin(), t);
                            ans.push_back(temp[k]);
                        }
                    }
                }
            }
            return ans;
        }
};
