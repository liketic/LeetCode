class Solution {
public:
    int numDistinct(string S, string T) {
        int n = S.length(), m = T.length();
        int d[n + 1][m + 1];
        memset(d, 0, sizeof(d));

        d[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            d[i][0] = 1;
            for (int j = 1; j <= m; j++) {
                if (S[i - 1] == T[j - 1])
                    d[i][j] = d[i - 1][j - 1];
                d[i][j] += d[i - 1][j];
            }
        }
        return d[n][m];
    }
};
