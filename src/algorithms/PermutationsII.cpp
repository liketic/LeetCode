class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        bool flag = true;
        int n = nums.size();
        vector<vector<int>> ans;

        while (flag) {
            vector<int> t;
            for (int i = 0; i < n; i++)
                t.push_back(nums[i]);
            ans.push_back(t);

            flag = false;

            for (int j = n - 2; j >= 0; j--) {
                bool hasMoreThan = false;
                int pos = 0;

                for (int k = j + 1; k < n; k++) {
                    if (nums[k] > nums[j]) {
                        if (hasMoreThan) {
                            if (nums[k] < nums[pos]) {
                                pos = k;
                            }
                        } else{
                            hasMoreThan = true;
                            pos = k;
                        }
                    }
                }
                if (hasMoreThan) {
                    int t = nums[j];
                    nums[j] = nums[pos];
                    nums[pos] = t;
                    flag = true;
                    sort(nums.begin() + j + 1, nums.end());
                    break;
                }
            }
        }
        return ans;
    }
};
