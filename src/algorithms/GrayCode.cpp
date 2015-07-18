class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);
        // confused by n == 0
        if (n == 0) return ans;
        ans.push_back(1);
        if (n == 1) return ans;

        for (int i = 2; i <= n; i++) {
            vector<int> temp(ans);
            for (int j = temp.size() - 1; j >= 0; j--) {
                ans.push_back(temp[j] + (1 << (i - 1)));
            }
        }
        return ans;
    }
};
