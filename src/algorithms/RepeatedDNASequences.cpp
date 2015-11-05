class Solution {
public:
    vector<string> findRepeatedDnaSequences(const string& s) {
        int n = s.length();
        vector<string> ans;
        vector<string> suffs;
        for (int i = 0; i <= n - 10; i++) {
            suffs.push_back(s.substr(i, 10));
        }
        sort(suffs.begin(), suffs.end());

        int numOfSuffx = suffs.size();

        for (int i = 1; i < numOfSuffx; i++) {
            if (suffs[i] == suffs[i - 1]) {
                ans.push_back(suffs[i]);
                for (int j = i + 1; j < numOfSuffx; j++) {
                    if (suffs[j] != suffs[i]) break;
                    i = j;
                }
            }
        }
        return ans;
    }
};
