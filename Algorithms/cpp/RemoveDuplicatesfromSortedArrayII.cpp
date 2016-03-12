class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0)
            return 0;
        int k = 0, t = 1;
        for (int i = 1; i < n; i++)
            if (A[i] == A[k]) {
                if (t < 2) {
                    A[++k] = A[i];
                    t++;
                }
            } else {
                A[++k] = A[i];
                t = 1;
            }
        return (++k);
    }
};
