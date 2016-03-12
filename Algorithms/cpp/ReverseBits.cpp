class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        int t = 0;
        while (t++ < 32) {
            ret = ret * 2 + n % 2;
            n /= 2;
        }
        return ret;
    }
};
