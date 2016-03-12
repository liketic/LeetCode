class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int ans = 0;
        int j = -1;

        for (int i = 1; i <= n; i++) {
            while (j + 1 < n && citations[j + 1] < i) {
                j++;
            }
            if (n - j - 1 >= i) {
                ans = max(ans, i);
            }
        }
        return ans;
    }
};
