int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
        int rNum = grid.size();
        if (rNum == 0)return 0;
        int cNum = grid[0].size();

        int ans = 0;
        for (int i = 0; i < rNum; i++) {
            for (int j = 0; j < cNum; j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    this->fillBlood(grid, i, j, rNum, cNum);
                }
            }
        }
        for (int i = 0; i < rNum; i++) {
            for (int j = 0; j < cNum; j++)
                if (grid[i][j] == '2')grid[i][j] = '1';
        }
        return ans;
    }
private:
    void fillBlood(vector<vector<char> >& grid, int x, int y, int r, int c) {
        grid[x][y] = '2';
        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx >= 0 && tx < r && ty >= 0 && ty < c && grid[tx][ty] == '1') {
                fillBlood(grid, tx, ty, r, c);
            }
        }
    }
};
