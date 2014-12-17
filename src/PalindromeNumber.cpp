class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)return 0;
        int t = 0, n = x;
        while (x)
        {
            t = t * 10 + x % 10;
            x /= 10;
        }
        return (t == n);
    }
};
