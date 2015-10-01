class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        return search(nums, target, l, r);
    }
private:
    bool search(vector<int>& nums, int target, int l, int r) {
        if (l > r) return false;
        int m = (l + r) / 2;
        if (nums[l] < nums[m]) {
            if (find(nums, target, l, m)) return true;
            return search(nums, target, m + 1, r);
        }
        if (nums[l] > nums[m]) {
            if (find(nums, target, m, r)) return true;
            return search(nums, target, l, m - 1);
        }
        if (nums[l] == nums[m]) {
            if (nums[l] == target) return true;
            return search(nums, target, m + 1, r) || search(nums, target, l + 1, m - 1);
        }
    }

    bool find(vector<int>& nums, int target, int l, int r) {
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] == target) {
                return true;
            }
            if (nums[m] > target) r = m - 1;
            else l = m + 1;
        }
        return false;
    }
};
