class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& bor) {
        if (!checkSize(bor)) return false;
        if (!checkEachRow(bor)) return false;
        if (!checkEachCol(bor)) return false;
        if (!checkSubBox(bor)) return false;
        return true;
    }
private:
    bool checkSubBox(vector<vector<char> >& bor) {
        bool is[9];

        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                memset(is, 0, sizeof(is));
                int t = 0;
                for (int r = i; r < i + 3; r++) {
                    for (int c = j; c < j + 3; c++) {
                        if (bor[r][c] == '.') t++;
                        else
                            is[bor[r][c] - '1'] = true;
                    }
                }
                for (int v = 0; v < 9; v++)
                    if (!is[v] && !t--) return false;
            }
        }
        return true;
    }
    bool checkEachRow(vector<vector<char> >& bor) {
        bool is[9];
        for (int r = 0; r < 9; r++) {
            memset(is, 0, sizeof(is));
            int t = 0;
            for (int c = 0; c < 9; c++) {
                if (bor[r][c] == '.')t++;
                else
                    is[bor[r][c] - '1'] = true;
            }
            for (int c = 0; c < 9; c++)
                if (!is[c] && !t--)return false;
        }
        return true;
    }
    bool checkEachCol(vector<vector<char> >& bor) {
        bool is[9];
        for (int c = 0; c < 9; c++) {
            memset(is, 0, sizeof(is));
            int t = 0;
            for (int r = 0; r < 9; r++) {
                if (bor[r][c] == '.')t++;
                else
                    is[bor[r][c] - '1'] = true;
            }
            for (int r = 0; r < 9; r++)
                if (!is[r] && !t--)return false;
        }
        return true;
    }
    bool checkSize(vector<vector<char> >& bor) {
        if (bor.size() != 9) return false;
        for (int i = 0; i < 9; i++) {
            if (bor[i].size() != 9) {
                return false;
            }
        }
        return true;
    }
};
