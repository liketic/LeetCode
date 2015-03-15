class Solution
{
public:
    void sortColors(int A[], int n)
    {
        int t[3];
        t[0] = t[1] = t[2] = 0;
        for (int i = 0; i < n; i++)
            t[A[i]]++;
        n = 0;
        for (int j = 0; j < 3; j++)
            for (int i = 0; i < t[j]; i++)
                A[n++] = j;
    }
};
