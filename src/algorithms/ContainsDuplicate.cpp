class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> dict;
        for (int i = 0; i < nums.size(); i++) {
            int t = nums[i];
            if (dict[t] > 0) return true;
            dict[t] = 1;
        }
        return false;
    }
};
