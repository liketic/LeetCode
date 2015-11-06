class Solution {
public:
    void rotate(vector<vector<int> >& mt) {
        int r = mt.size();
        if (r == 0) return;


        for (int i = 0; i < r / 2; i++) {
            for (int j = i; j < r - i - 1; j++) {
                int x = i, y = j;
                int xx, yy;
                int v = mt[x][y];

                for (int k = 0; k < 4; k++) {
                    xx = y;
                    yy = r - x - 1;
                    int tt = mt[xx][yy];
                    x = xx;
                    y = yy;
                    mt[xx][yy] = v;
                    v = tt;
                }
            }
        }
    }
};
