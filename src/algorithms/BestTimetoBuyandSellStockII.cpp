
class Solution {
public:
    int maxProfit(vector<int> &p) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int n = p.size();
        int s = 0;

        for (int i = 0; i < n - 1; i++)
            if (p[i] < p[i + 1])
                s += p[i + 1] - p[i];
        return s;
    }
};
