class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int n = matrix.size();
        if (n == 0)return;
        int m = matrix[0].size();
        bool r[n], c[m];

        memset(r, 0, sizeof(r));
        memset(c, 0, sizeof(c));

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; j++)
                if (!matrix[i][j])
                    r[i] = c[j] = 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (r[i] || c[j])
                    matrix[i][j] = 0;
    }
};
