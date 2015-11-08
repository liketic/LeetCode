class Solution {
public:
    string longestCommonPrefix(vector<string> &str) {

        int n = str.size();
        if (n == 0)return "";
        int k = str[0].length();

        for (int i = 1; i < n; i++) {
            int m = str[i].length();
            int len = min(m, k);
            for (int j = 0; j < len; j++)
                if (str[i][j] != str[i - 1][j]) {
                    k = j;
                    break;
                }
            k = min(len, k);
        }
        return str[0].substr(0, k);
    }
};
