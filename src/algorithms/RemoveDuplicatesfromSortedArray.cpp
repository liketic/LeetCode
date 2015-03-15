class Solution
{
public:
    int removeDuplicates(int a[], int n)
    {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (!n)return 0;
        int x = 0;
        int ans = 1;
        for (int i = 1; i < n; i++)
            if (a[i] != a[x])
            {
                x = i;
                a[ans++] = a[i];
            }
        return ans;
    }
};
