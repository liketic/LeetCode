class Solution
{
public:
    int atoi(const char *str)
    {
        int len = strlen(str);
        if (len == 0)
            return 0;
        long long ans = 0, i = 0, j = 1;

        while (str[i] && !isalnum(str[i])
                && str[i] != '+' && str[i] != '-')
            ++i;
        if (str[i] == '-' || str[i] == '+')
        {
            j = str[i] == '-' ? -1 : 1;
            ++i;
        }
        for (; str[i] && isdigit(str[i]); i++)
            ans = ans * 10 + (str[i] - '0');
        ans *= j;
        if (ans > 2147483647LL)
            ans = 2147483647LL;
        if (ans < -2147483648LL)
            ans = -2147483648LL;
        return ans;
    }
};
