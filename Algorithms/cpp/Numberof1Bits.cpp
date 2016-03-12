class Solution {
public:
    int hammingWeight(uint32_t n) {
        int t = 0;
        while (n) {
            t += n % 2;
            n /= 2;
        }
        return t;
    }
};
