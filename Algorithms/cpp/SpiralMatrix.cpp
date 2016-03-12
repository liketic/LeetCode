class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &m) {

        int n = m.size();
        vector<int> ans;

        if (n == 0)
            return ans;
        int q = m[0].size(), t = 0;

        bool vis[n + 2][q + 2];
        memset(vis, 0, sizeof(vis));

        int x = 1, y = 1;

        for (int i = 0; i < n + 2; i++)
            vis[i][0] = vis[i][q + 1] = 1;
        for (int i = 0; i < q + 2; i++)
            vis[0][i] = vis[n + 1][i] = 1;

        while (t < q * n) {
            int j = y;
            while (!vis[x][j]) {
                ans.push_back(m[x - 1][j - 1]);
                vis[x][j] = 1;
                t++;
                if (vis[x][j + 1])break;
                j++;
            }
            int i = x + 1;
            while (!vis[i][j]) {
                ans.push_back(m[i - 1][j - 1]);
                vis[i][j] = 1;
                t++;
                if (vis[i + 1][j])break;
                i++;
            }
            j--;
            while (!vis[i][j]) {
                ans.push_back(m[i - 1][j - 1]);
                vis[i][j] = 1;
                t++;
                if (vis[i][j - 1])break;
                j--;
            }
            i--;
            while (!vis[i][j]) {
                ans.push_back(m[i - 1][j - 1]);
                vis[i][j] = 1;
                t++;
                if (vis[i - 1][j])break;
                i--;
            }
            x++;
            y++;
        }
    }
};
