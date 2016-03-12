class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &ob) {
        int n = ob.size();
        int m = ob[0].size();
        int d[n][m];
        memset(d, 0, sizeof(n, m));

        d[0][0] = 1;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (ob[i][j])
                    d[i][j] = 0;
                else if (i == j && i == 0)
                    continue;
                else if (i && j == 0)
                    d[i][j] = d[i - 1][j];
                else if (i == 0 && j)
                    d[i][j] = d[i][j - 1];
                else d[i][j] = d[i - 1][j] + d[i][j - 1];
        return d[n - 1][m - 1];
    }
};
