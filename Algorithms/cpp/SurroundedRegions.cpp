struct node {
    int x, y;
};
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
const int MAX_SIZE = 1000000;
const int N = 1001;
node d[MAX_SIZE];
bool vis[N][N];
int v[N][N];

class Solution {
private:
    void bfs(vector< vector<char> > &b, int i, int j) {
        int f = 0, r = 0;
        v[i][j] = 1;
        d[r].x = i;
        d[r].y = j;
        r++;
        vis[i][j] = 1;

        while (f < r) {

            int tx = d[f].x, ty = d[f].y;
            for (int i = 0; i < 4; i++) {
                int cx = tx + dx[i];
                int cy = ty + dy[i];
                if (cx >= 0 && cx < b.size() && cy >= 0 && cy < b[cx].size()) {
                    if (b[cx][cy] == 'O' && !vis[cx][cy]) {
                        v[cx][cy] = 1;
                        vis[cx][cy] = 1;
                        d[r].x = cx;
                        d[r].y = cy;
                        r++;
                    }
                }
            }
            f++;
        }
    }

public:
    void solve(vector<vector<char> > &b) {
        memset(vis, 0, sizeof(vis));
        int n = b.size();
        memset(v, 0, sizeof(v));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < b[i].size(); j++) {
                if ((i == 0 || i == n - 1 || j == 0 || j == b[i].size() - 1)
                    && b[i][j] == 'O' && !v[i][j]) {
                    this->bfs(b, i, j);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < b[i].size(); j++) {
                if (!v[i][j]) {
                    b[i][j] = 'X';
                }
            }
        }
    }
};
