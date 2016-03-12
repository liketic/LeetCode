const int MAX_SIZE = 100;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

class Solution {
private:
    bool vis[MAX_SIZE][MAX_SIZE];
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (word.size() == 0) {
            return true;
        }
        int r = board.size();
        if (r == 0) {
            return false;
        }
        int c = board[0].size();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == word[0]) {
                    memset(vis, 0, sizeof(vis));
                    if(dfs(board, i, j, word)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char> > &b, int x, int y, string w) {
        int len = w.size();
        if (len == 0) {
            return true;
        }
        if (vis[x][y] || b[x][y] != w[0]) {
            vis[x][y] = 0;
            return false;
        }
        vis[x][y] = 1;
        if (len == 1) {
            return true;
        }
        string s = w.substr(1, w.size() - 1);
        int tx, ty;
        for (int i = 0; i < 4; i++) {
            tx = dx[i] + x;
            ty = dy[i] + y;
            if (tx >= 0 && tx < b.size() && ty >= 0 && ty < b[x].size() && !vis[tx][ty] && dfs(b, tx, ty, s)) {
                return true;
            }
        }
        vis[x][y] = 0;
        return false;
    }
};
