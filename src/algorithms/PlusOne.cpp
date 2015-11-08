class Solution {
public:
    vector<int> plusOne(vector<int> &d) {
        int len = d.size();
        d[len - 1]++;
        for (int i = len - 1; i > 0; i--) {
            if (d[i] >= 10) {
                d[i] %= 10;
                d[i - 1] ++;
            } else break;
        }
        if (d[0] >= 10) {
            d[0] %= 10;
            d.insert(d.begin(), 1);
        }
        return d;
    }
};
