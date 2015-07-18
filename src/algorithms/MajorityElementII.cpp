class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int v[2], c[2];
        int n = nums.size();
        memset(c, 0, sizeof(c));

        for(int i = 0; i < n; i++) {
            bool flag = true;
            for (int j = 0; j < 2; j++) {
                if (c[j] && v[j] == nums[i]) {
                    c[j]++;
                    flag = false;
                    break;
                }
            }
            if (!flag)continue;
            for (int j = 0; j < 2; j++) {
                if (!c[j]) {
                    c[j] = 1;
                    v[j] = nums[i];
                    flag = false;
                    break;
                }
            }
            if (flag) {
                for (int j = 0; j < 2; j++) {
                    c[j]--;
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < 2; i++)
            if (c[i]) {
                int t = 0;
                for (int j = 0; j < n; j++)
                    t += (nums[j] == v[i]);
                if (t > n / 3)
                    ans.push_back(v[i]);
            }
        return ans;
    }
};
