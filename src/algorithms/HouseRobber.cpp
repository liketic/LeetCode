class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int *d = new int[n];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0) d[i] = nums[i];
            else {
                int m = 0;
                for (int j = 0; j < i - 1; j++)
                    m = max(m, d[j]);
                d[i] = m + nums[i];
            }
            ans = max(ans, d[i]);
        }
        delete d;
        d = NULL;

        return ans;
    }
};
