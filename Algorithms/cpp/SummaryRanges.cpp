class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        if (n == 0) return ans;

        int t = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] != nums[i + 1] - 1) {
                ans.push_back(toRange(nums[t], nums[i]));
                t = i + 1;
            }
        }
        ans.push_back(toRange(nums[t], nums[n - 1]));
        return ans;
    }
private:
    string toRange(int l, int r) {
        string s = toStr(l);
        if (l == r) return s;
        s += "->";
        s += toStr(r);
        return s;
    }
    string toStr(int v) {
        ostringstream oss;
        oss << v;
        return oss.str();
    }
};
