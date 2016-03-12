class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int pre[n], next[n];

        for (int i = 0; i < n; i++) {
            pre[i] = i == 0 ? nums[i] : nums[i] * pre[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            next[i] = i == n - 1 ? nums[i] : next[i + 1] * nums[i];
        }
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            int temp = 1;
            if (i < n - 1)temp *= next[i + 1];
            if (i > 0) temp *= pre[i - 1];
            ans.push_back(temp);
        }
        return ans;
    }
};
