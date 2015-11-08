class Solution {
    bool d[202][102][102];
public:
    bool isInterleave(string s1, string s2, string s3) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        memset(d, 0, sizeof(d));
        int sizeOfS1 = s1.size(), sizeOfS2 = s2.size(), sizeOfS3 = s3.size();

        for (int i = 0; i <= sizeOfS1; i++)
            for (int j = 0; j <= sizeOfS2; j++)
                for (int k = 0; k <= sizeOfS3; k++) {

                    if (i == 0) {
                        if (!j && !k)
                            d[i][j][k] = 1;
                        continue;
                    }

                    if (j == 0) {
                        if (i == k && s3.substr(0, i) == s2.substr(0, k)) {
                            d[i][j][k] = 1;
                        }
                        continue;
                    }

                    if (k == 0) {
                        if (i == j && s3.substr(0, i) == s1.substr(0, j)) {
                            d[i][j][k] = 1;
                        }
                        continue;
                    }

                    if (s3[i - 1] == s1[j - 1])
                        d[i][j][k] += d[i - 1][j - 1][k];
                    if (s3[i - 1] == s2[k - 1])
                        d[i][j][k] += d[i - 1][j][k - 1];
                }

        return d[l3][l1][l2];
    }
};
