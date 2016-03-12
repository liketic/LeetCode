class Solution {
public:
    int countPrimes(int n) {
        int *is = new int[n + 1];
        for (int i = 1; i < n; i++)
            is[i] = 0;
        int ans = 0;
        for (int i = 2; i < n; i++) {
            if (is[i]) {
                continue;
            }
            ans++;
            for (int j = i; j < n; j += i) {
                is[j] = 1;
            }
        }
        delete is;
        is = NULL;
        return ans;
    }
};
