class Solution {
public:
    int trap(vector<int>& x) {
        int ans = 0;
        int n = x.size();

        int s[n];
        for (int i = 0; i < n; i++) {
            if (i == 0) s[i] = x[i];
            else {
                s[i] = s[i - 1] + x[i];
            }
        }

        int tt = n;

        for (int i = 0; i < n; i++) {
            if (x[i] > 0) {
                int j = i + 1;
                while (j < n && x[j] < x[i]) {
                    j++;
                }
                if (j < n) {
                    ans += x[i] * (j - i - 1) - (s[j - 1] - s[i]);
                } else {
                    tt = i;
                    break;
                }
                i = j - 1;
            }
        }

        for (int i = n - 1; i >= tt; i--) {
            if (x[i] > 0) {
                int j = i - 1;
                while (j >= tt && x[j] < x[i]) {
                    j--;
                }
                if (j >= tt) {
                    ans += x[i] * (i - j - 1) - (s[i - 1] - s[j]);
                } else {
                    break;
                }
                i = j + 1;
            }
        }
        return ans;

    }
};
