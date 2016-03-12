class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int sizeOfNums = nums.size();

        for (int i = 0; i < sizeOfNums; i++) {
            if (nums[i]) {
                continue;
            }
            for (int j = i + 1; j < sizeOfNums; j++) {
                if (nums[j] != 0) {
                    nums[i] = nums[j];
                    nums[j] = 0;
                    break;
                }
            }
        }
    }
};
