class Solution {
public:
    void gameOfLife(vector<vector<int>>& bd) {
        int m = bd.size();
        if (m == 0) return;
        int n = bd[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int liveCount = 0;
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        if (!dx && !dy) continue;
                        if (isLived(i + dx, j + dy, m, n, bd)) {
                            liveCount++;
                        }
                    }
                }
                if (isLived(bd[i][j])) {
                    if (liveCount < 2) {
                        // dies
                    } else if (liveCount == 2 || liveCount == 3) {
                        bd[i][j] += 2;
                    } else if (liveCount > 3) {
                        // dies
                    }
                } else {
                    if (liveCount == 3) {
                        bd[i][j] += 2;
                    }
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bd[i][j] >>= 1;
            }
        }
    }

    bool onMaze(int x, int y, int m, int n) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }

    bool isLived(int v) {
        return (v % 2 == 1);
    }

    bool isLived(int x, int y, int m, int n, vector<vector<int>>& bd) {
        return onMaze(x, y, m, n) && isLived(bd[x][y]);
    }
};
