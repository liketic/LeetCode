class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        int d[n + 1][m + 1];
        memset(d, 0, sizeof(d));

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0)
                    d[i][j] = i + j;
                else if (word1[i - 1] == word2[j - 1]) {
                    d[i][j] = d[i - 1][j - 1];
                } else {
                    d[i][j] = 1 + min(d[i - 1][j - 1],
                                      min(d[i - 1][j], d[i][j - 1]));
                }
            }
        }
        return d[n][m];
    }
};
