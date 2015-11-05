class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        int d[len];
        int ans = 0;

        for (int i = 0; i < len; i++) {
            int t = 0;
            for (int j = 0; j< i; j++) {
                if (nums[j] < nums[i]) {
                    t = max(t, d[j]);
                }
            }
            d[i] = t + 1;
            ans = max(ans, d[i]);
        }
        return ans;
    }
};
