class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // if less than two elements, cannot complete any transactions
        if (n < 2) return 0;
        int ans = 0;
        int left[n], right[n];

        // to every i, find max profit before i(included)
        left[0] = 0;
        int v = prices[0];
        for (int i = 1; i < n; i++) {
            left[i] = max(left[i - 1], prices[i] - v);
            v = min(v, prices[i]);
        }

        //  to every i, find max profit after i
        right[n - 1] = 0;
        v = prices[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], v - prices[i]);
            v = max(v, prices[i]);
        }
        ans = max(ans, right[0]);
        for (int i = 0; i < n - 1; i++) {
            ans = max(ans, left[i] + right[i + 1]);
        }
        ans = max(ans, left[n - 1]);

        return ans;
    }
};

