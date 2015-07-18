const int INF = 10000000;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        int n = nums.size();

        while (true) {
            vector<int> temp(nums);
            ans.push_back(temp);
            bool flag = false;
            for (int i = n - 1; i > 0; i--) {
                if (nums[i] > nums[i - 1]) {
                    flag = true;
                    int dis = INF;
                    int index = -1;
                    for (int j = n - 1; j >= i; j--) {
                        if (nums[j] > nums[i - 1] && dis > nums[j] - nums[i - 1]) {
                            dis = nums[j] - nums[i - 1];
                            index = j;
                        }
                    }
                    int cur = nums[i - 1];
                    nums[i - 1] = nums[index];
                    nums[index] = cur;
                    sort(nums.begin() + i, nums.end());
                    break;
                }
            }
            if (!flag) break;
        }
        return ans;
    }
};
