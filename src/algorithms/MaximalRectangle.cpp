#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector< vector<char> > &matrix) {
        int rowcount = matrix.size();
        if (rowcount == 0) return 0;

        int colcount = matrix[0].size();
        const int INF = 1 << 24;

        int c[rowcount][colcount], r[rowcount][colcount];

        for (int i = 0;i < rowcount; i++) {
            for (int j = 0; j < colcount; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0) {
                        c[i][j] = i;
                    } else {
                        c[i][j] = min(c[i - 1][j], i);
                    }
                    if (j == 0) {
                        r[i][j] = j;
                    } else {
                        r[i][j] = min(r[i][j - 1], j);
                    }
                } else {
                    c[i][j] = r[i][j] = INF;
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < rowcount; i++) {
            for (int j = 0; j < colcount; j++) {
                if (matrix[i][j] == '0') {
                    continue;
                }
                int rs = 0;
                for (int k = i; k >= c[i][j]; k--) {
                    rs = max(rs, r[k][j]);
                    ans = max(ans, (j - rs + 1) * (i - k + 1));
                }
                rs = 0;
                for (int k = j; k >= r[i][j]; k--) {
                    rs = max(rs, c[i][k]);
                    ans = max(ans, (j - k + 1) * (i - rs + 1));
                }
            }
        }
        return ans;
    }
};


int main() {

    vector< vector<char> > c;
    vector<char> x;
    x.push_back('1');
    x.push_back('1');
    x.push_back('0');
    x.push_back('1');
    vector<char> y;
    y.push_back('1');
    y.push_back('1');
    y.push_back('0');
    y.push_back('1');
    vector<char> z;
    z.push_back('1');
    z.push_back('1');
    z.push_back('1');
    z.push_back('1');

    c.push_back(x);
    c.push_back(y);
    c.push_back(z);

    Solution s;

    cout << s.maximalRectangle(c) << endl;

    return 0;
}
