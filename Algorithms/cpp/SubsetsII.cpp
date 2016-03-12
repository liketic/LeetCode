class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int lenOfNums = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        for (int i = 0; i < (1 << lenOfNums); i++) {
            vector<int> tt;
            for (int j = 0; j < lenOfNums; j++) {
                if (i & (1 << j)) {
                    tt.push_back(nums[j]);
                }
            }
            addIfNotExist(ans, tt);
        }
        return ans;
    }

    void addIfNotExist(vector<vector<int>>& a, vector<int>& b) {
        int len = a.size();
        for (int i = 0; i < len; i++) {
            if (isEqual(a[i], b)) {
                return;
            }
        }
        a.push_back(b);
    }

    bool isEqual(vector<int>& a, vector<int>& b) {
        int lenOfA = a.size(), lenOfB = b.size();
        if (lenOfA != lenOfB) {
            return false;
        }
        for (int i = 0; i < lenOfA; i++) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }
};
