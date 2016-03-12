class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int t = 1;
        while (n - m > 1) {
            t <<= 1;
            n >>= 1;
            m >>= 1;
        }
        int ans = m;
        for (long long i = (long long)m + 1; i <= n; i++) {
            ans &= i;
        }
        return ans * t;
    }
};
