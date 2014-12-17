class Solution
{
public:
    vector<vector<int> > generateMatrix(int n)
    {
        vector< vector<int> > ans;

        for (int i = 0; i < n; i++)
        {
            vector<int> p(n, 0);
            ans.push_back(p);
        }

        if (n == 0)
            return ans;
        int q = n, t = 0;

        bool vis[n + 2][q + 2];
        memset(vis, 0, sizeof(vis));

        int x = 1, y = 1;

        for (int i = 0; i < n + 2; i++)
            vis[i][0] = vis[i][q + 1] = 1;
        for (int i = 0; i < q + 2; i++)
            vis[0][i] = vis[n + 1][i] = 1;

        while (t < q * n)
        {
            int j = y;
            while (!vis[x][j])
            {
                ans[x - 1][j - 1] = ++t;
                vis[x][j] = 1;
                if (vis[x][j + 1])break;
                j++;
            }
            int i = x + 1;
            while (!vis[i][j])
            {
                ans[i - 1][j - 1] = ++t;
                vis[i][j] = 1;
                if (vis[i + 1][j])break;
                i++;
            }
            j--;
            while (!vis[i][j])
            {
                ans[i - 1][j - 1] = ++t;
                vis[i][j] = 1;
                if (vis[i][j - 1])break;
                j--;
            }
            i--;
            while (!vis[i][j])
            {
                ans[i - 1][j - 1] = ++t;
                vis[i][j] = 1;
                if (vis[i - 1][j])break;
                i--;
            }
            x++;
            y++;
        }
        return ans;
    }
};
