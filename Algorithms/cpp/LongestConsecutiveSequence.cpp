class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        int maxf = 0;
        int n = num.size();
        int k = 0;

        for (int i = 0; i < n; ++i) {
            if (num[i] >= n)
                continue;
            num[k++] = num[i];
            maxf = max(maxf, num[i]);
        }
        n = k;
        int p[maxf];
        int ans = 0;
        memset(p, 0, sizeof(p));

        for (int i = 0; i < n; ++i) {
            if (num[i] && p[num[i] - 1])
                p[num[i]] = p[num[i] - 1] + 1;
            else
                p[num[i]] = 1;
            ans = max(ans, p[num[i]]);
        }
        return ans;
    }
};
