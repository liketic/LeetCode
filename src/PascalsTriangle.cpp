class Solution {
public:
    vector<vector<int> > generate(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector< vector<int>> ans;
        for (int i = 1; i <= n; i++) {
            vector<int> x;
            for (int j = 1; j <= i; j++)
            {
                if (j == 1 || j == i)
                    x.push_back(1);
                else {
                    x.push_back(ans[i - 2][j - 2] + ans[i - 2][j - 1]);
                }
            }
            ans.push_back(x);
        }
        return ans;
    }
};
