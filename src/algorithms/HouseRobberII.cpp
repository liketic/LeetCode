class Solution {
public:
    int rob(vector<int>& nums) {
        // not a real cycle
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        vector<int> arr;
        int ans = 0;
        for (int i = 0; i < nums.size() - 1; i++)
            arr.push_back(nums[i]);
        ans = max(ans, calcuate(arr));
        arr.clear();
        for (int i = 1; i < nums.size(); i++)
            arr.push_back(nums[i]);
        ans = max(ans, calcuate(arr));
        return ans;
    }
private:
    int calcuate(vector<int>& vs) {
        int n = vs.size();
        int* d = new int[n + 1];
        for (int i = 0; i < n + 1; i++)
            d[i] = 0;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int v = 0;
            for (int j = 0; j < i - 1; j++) {
                v = max(v, d[j]);
            }
            d[i] = v + vs[i - 1];
            ans = max(ans, d[i]);
        }
        delete d;
        d = NULL;
        return ans;
    }
};
