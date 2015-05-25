class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int t = 1;
        while (n - m > 1) {
            t *= 2;
            n /= 2;
            m /= 2;
        }
        int ans = m;
        for (long long i = (long long)m + 1; i <= n; i++) {
            ans &= i;
        }
        return ans * t;
    }
};
