class Solution
{
public:
    int minimumTotal(vector<vector<int> > &t)
    {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int n = t.size();
        int m = t[0].size();
        for (int i = n - 2; i >= 0; i--)
            for (int j = 0; j < t[i].size(); j++)
                t[i][j] += min(t[i + 1][j], t[i + 1][j + 1]);
        return t[0][0];
    }
};
