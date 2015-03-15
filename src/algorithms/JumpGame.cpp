class Solution
{
public:

    bool canJump(int A[], int n)
    {
        bool B[n + 1];
        memset(B, 0, sizeof(B));
        int t = 0;
        B[0] = 1;
        for (int i = 0; i < n; i++)
            if (B[i] || i <= t)
            {
                t = max(t, i + A[i]);
            }
        return (t >= n - 1);
    }
};
