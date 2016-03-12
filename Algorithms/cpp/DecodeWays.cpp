#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (n == 0) {
            return 0;
        }
        int c[n + 1];
        c[0] = 1;

        for (int i = 1; i <= n; i++) {
            c[i] = 0;
            for (int j = i; j >= i - 1 && j >= 1; j--) {
                if (s[j - 1] == '0') {
                    continue;
                }
                int t = 0;
                for (int k = j; k <= i; k++)
                    t = t * 10 + (s[k - 1] - '0');
                if (t >= 1 && t <= 26) {
                    c[i] += c[j - 1];
                }
            }
        }
        return c[n];
    }
};
