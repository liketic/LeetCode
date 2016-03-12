class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        if (len == 1) return nums[0];
        vector<int> a, b;

        int t = nums[len / 2];
        int i = 0;

        while (i < len) {
            if (nums[i] > t) {
                a.push_back(nums[i]);
            } else if (nums[i] < t) {
                b.push_back(nums[i]);
            }
            i++;
        }
        if (k <= a.size()) {
            return findKthLargest(a, k);
        } else if (k <= len - b.size()) {
            return t;
        } else {
            return findKthLargest(b, k - (len - b.size()));
        }
    }
};
