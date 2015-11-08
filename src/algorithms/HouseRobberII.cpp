class Solution {
public:
    int rob(vector<int>& nums) {
        int sizeOfNums = nums.size();
        // not a real cycle
        if (sizeOfNums == 0) return 0;
        if (sizeOfNums == 1) return nums[0];

        vector<int> arr;
        int ans = 0;
        for (int i = 0; i < sizeOfNums - 1; i++)
            arr.push_back(nums[i]);
        ans = max(ans, calcuate(arr));
        arr.clear();
        for (int i = 1; i < sizeOfNums; i++)
            arr.push_back(nums[i]);
        ans = max(ans, calcuate(arr));
        return ans;
    }
private:
    int calcuate(vector<int>& vs) {
        int n = vs.size();
        int d[n + 1];
        memset(d, 0, sizeof(d));

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int v = 0;
            for (int j = 0; j < i - 1; j++) {
                v = max(v, d[j]);
            }
            d[i] = v + vs[i - 1];
            ans = max(ans, d[i]);
        }
        return ans;
    }
};
