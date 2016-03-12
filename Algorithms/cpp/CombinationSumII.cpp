class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return dfs(candidates, candidates.size() - 1, target);
    }

    vector<vector<int>> dfs(vector<int>& nums, int pos, int tt) {
        vector<vector<int>> v;
        if (tt == 0) {
            vector<int> x;
            v.push_back(x);
            return v;
        }

        int len = nums.size();
        int temp;

        for (int j = pos; j >= 0; j--) {
            if (nums[j] <= tt) {
                vector<vector<int>> t = dfs(nums, j - 1, tt - nums[j]);
                temp = t.size();
                for (int i = 0; i < temp; i++) {
                    t[i].push_back(nums[j]);
                    bool flag = true;
                    int lenOfV = v.size();
                    for (int k = 0; k < lenOfV; k++) {
                        if (isEqual(v[k], t[i])) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) v.push_back(t[i]);
                }
            }
        }
        return v;
    }

    bool isEqual(vector<int>& a, vector<int>& b) {
        int lenOfA = a.size(), lenOfB = b.size();
        if (lenOfA != lenOfB) return false;
        for (int i = 0; i < lenOfA; i++) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }
};
