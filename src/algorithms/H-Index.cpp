class Solution {
public:
    int hIndex(vector<int>& citations) {
        int ans = 0;
        for (int i = 0; i <= citations.size(); i++) {
            int t = 0;
            for (int j = 0; j < citations.size(); j++) {
                if (citations[j] >= i) t++;
            }
            if (t >= i) {
                ans = max(ans, i);
            }
        }
        return ans;
    }
};
