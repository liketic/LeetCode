class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        int d[101][101];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    d[i][j] = 1;
                else if (i == 0)
                    d[i][j] = d[i][j - 1];
                else if (j == 0)
                    d[i][j] = d[i - 1][j];
                else d[i][j] = d[i - 1][j] + d[i][j - 1];
            }
        return d[m - 1][n - 1];
    }
};
