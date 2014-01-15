class Solution {
    public:
        int search(int A[], int n, int target) {
            int l = 0, r = n - 1;

            while (l <= r) {
                int m = (l + r) / 2;
                if (A[m] == target)
                    return m;
                if (A[l] <= A[m]) {
                    if (target >= A[l] && target <= A[m]) 
                        r = m - 1;
                    else l = m + 1;
                }
                else {
                    if (target >= A[m] && target <= A[r])
                        l = m + 1;
                    else r = m - 1;
                }
            }
            return -1;
        }
};
