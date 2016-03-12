class Solution {
public:
    int numSquares(int n) {
        if (n == 0) {
            return 0;
        }
        vector<int> x;
        for (int i = 1; i * i <= n; i++) {
            x.push_back(i * i);
        }
        int is[n + 1];
        for (int i = 1; i <= n; i++) {
            is[i] = n;
        }
        is[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < x.size(); j++) {
                if (i >= x[j]) {
                    is[i] = min(is[i], is[i - x[j]] + 1);
                }
            }
        }
        return is[n];
    }
};
