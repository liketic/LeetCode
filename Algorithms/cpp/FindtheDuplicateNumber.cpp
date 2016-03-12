class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        int n = len - 1;

        int l = 1, r = n;

        while (l < r) {
            int mid = (l + r) / 2;
            int tt = 0;
            for (int i = 0; i < len; i++) {
                if (nums[i] <= mid) {
                    tt++;
                }
            }
            if (tt > mid) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
