class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        return this->combineSumRecur(k, min(n, 9), n);
    }
private:
    vector<vector<int> > combineSumRecur(int k, int maxValue, int total) {
        vector<vector<int> > ans;
        if (k == 1) {
            if (total <= maxValue) {
                vector<int> v;
                v.push_back(total);
                ans.push_back(v);
            }
            return ans;
        }
        for (int i = 1; i <= maxValue && i < total; i++) {
            vector<vector<int> > t = combineSumRecur(k - 1, i - 1, total - i);
            for (int j = 0; j < t.size(); j++) {
                t[j].push_back(i);
                ans.push_back(t[j]);
            }
        }
        return ans;
    }
};
