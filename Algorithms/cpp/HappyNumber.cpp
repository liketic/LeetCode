#include <string.h>
#include <iostream>

class Solution {
public:
    bool isHappy(int n) {
        if (n <= 0) return false;
        int v[3000];
        memset(v, 0, sizeof(v));

        while (n > 1) {
            int m = 0;
            int temp;
            while (n) {
                temp = n % 10;
                m += temp * temp;
                n /= 10;
            }
            n = m;
            if (v[n]) return false;
            v[n] = 1;
        }
        return (n == 1);
    }
};
