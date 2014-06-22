class Solution {
public:
    int sqrt(int x) {
        long long l = 0, r = x;
        while (l <= r) {
            long long m = (l + r) / 2;
            if (m * m == x)
                return m;
            else if (m * m < x)
                l = m + 1;
            else r = m - 1;
        }
        return r;
    }
};
