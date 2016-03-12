class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> dict;
        int lenOfNums = nums.size();

        for (int i = 0; i < lenOfNums; i++) {
            int t = nums[i];
            if (dict[t] > 0) return true;
            dict[t] = 1;
        }
        return false;
    }
};
