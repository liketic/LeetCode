class Solution
{
public:
    int reverse(int x)
    {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int a[15];
        int k = 0;
        int p = 1;
        if (x < 0)
        {
            p = -1;
            x *= -1;
        }


        while (x)
        {
            a[k++] = x % 10;
            x /= 10;
        }

        int i = 0;

        while (!a[i])i++;
        int ans = 0;
        for (int i = 0; i < k; i++)
            ans = ans * 10 + a[i];
        ans *= p;
        return ans;
    }
};
