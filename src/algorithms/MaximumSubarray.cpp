class Solution {
public:
    int maxSubArray(int A[], int n) {
        int s = -1000000, t = 0;
        for (int i = 0; i < n; i++) {
            t += A[i];
            s = max(s, t);
            t = max(0, t);
        }
        return s;
    }
};
