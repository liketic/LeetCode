class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxPos = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++)
            if (i == 0 || i <= maxPos) {
                maxPos = max(maxPos, i + nums[i]);
            }
        return (maxPos >= n - 1);
    }
};
