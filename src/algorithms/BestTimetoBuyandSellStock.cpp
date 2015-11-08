class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int p = 100000000;
        int q = 0;

        int n = prices.size();

        for (int i = 0; i < n; i++) {
            q = max(q, prices[i] - p);
            p = min(p, prices[i]);
        }
        return q;
    }
};
