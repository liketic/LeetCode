class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        int r = matrix.size();
        if (r == 0) return 0;
        int c = matrix[0].size();
        memset(sum, 0, sizeof(sum));
        int ans = 0;

        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (matrix[i - 1][j - 1] == '1') {
                    sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + 1;
                    int l = 1, r = min(i, j);
                    while (l <= r) {
                        int m = (l + r) / 2;
                        int tx = i - m, ty = j - m;
                        int temp = sum[i][j] - sum[tx][j] - sum[i][ty] + sum[tx][ty];
                        if (temp < m * m) {
                            r = m - 1;
                        } else {
                            l = m + 1;
                            ans = max(ans, m);
                        }
                    }
                } else {
                    sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
                }
            }
        }
        return ans * ans;
    }
private:
    int sum[1001][1001];
};
