class Solution {
public:
    bool searchMatrix(vector<vector<int> > &ma, int ta) {
        int n = ma.size();
        if (n == 0)return 0;
        int m = ma[0].size();
        int r1 = 0, r2 = n - 1;

        while (r1 <= r2) {
            int r = (r1 + r2) / 2;
            if (ma[r][0] > ta)
                r2 = r - 1;
            else r1 = r + 1;
        }
        if (r2 > n - 1 || r2 < 0 || ma[r2][0] > ta)
            return 0;
        int l1 = 0, l2 = m - 1;
        while (l1 <= l2) {
            int mi = (l1 + l2) / 2;
            if (ma[r2][mi] == ta)
                return 1;
            else if (ma[r2][mi] > ta)
                l2 = mi - 1;
            else l1 = mi + 1;
        }
        return 0;
    }
};
