class Solution {
public:
    int climbStairs(int n) {
        int d[n + 1];
        d[0] = 1;
        for (int i = 1; i <= n; i++) {
            d[i] = d[i - 1];
            d[i] += i > 1 ? d[i - 2] : 0;
        }
        return d[n];
    }
};
