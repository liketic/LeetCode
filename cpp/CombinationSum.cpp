class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &ca, int ta) {
        vector<vector<int> >ans;
        if (ta == 0) {
            vector<int> t;
            ans.push_back(t);
            return ans;
        }
        sort(ca.begin(), ca.end());

        for (int i = 0; i * ca[0] <= ta; i++) {
            vector<int> temp(ca.begin() + 1, ca.end());
            if (temp.size() == 0 && ta - i * ca[0])
                continue;
            vector<vector<int> > x = combinationSum(temp, ta - i * ca[0]);
            int su = x.size();
            for (int j = 0; j < su; j++) {
                vector<int> y(i, ca[0]);
                copy(x[j].begin(), x[j].end(), back_inserter(y));
                ans.push_back(y);
            }
        }
        return ans;
    }
};
