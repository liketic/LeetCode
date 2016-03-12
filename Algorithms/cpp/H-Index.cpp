class Solution {
public:
    int hIndex(vector<int>& citations) {
        int ans = 0;
        int sizeOfCitations = citations.size();

        for (int i = 0; i <= sizeOfCitations; i++) {
            int t = 0;
            for (int j = 0; j < sizeOfCitations; j++) {
                if (citations[j] >= i) t++;
            }
            if (t >= i) {
                ans = max(ans, i);
            }
        }
        return ans;
    }
};
