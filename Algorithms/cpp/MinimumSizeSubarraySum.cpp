class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int count = nums.size();
        int *sum = new int[count + 1];
        sum[0] = 0;

        for (int i = 0; i < count; i++) {
            sum[i + 1] = nums[i] + sum[i];
        }
        int l = 1, r = count;
        int ans = count + 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (this->isOk(sum, count, m, s)) {
                ans = min(ans, m);
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        delete sum;
        sum = NULL;
        return (ans == count + 1 ? 0 : ans);
    }
private:
    bool isOk(int *sum, int n, int size, int v) {
        for (int i = size; i <= n; i++) {
            if (sum[i] - sum[i - size] >= v) {
                return true;
            }
        }
        return false;
    }
};
