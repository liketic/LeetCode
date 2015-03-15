class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int len = s.length();
        int d[26], t = 0, ans = 0, c[26];
        memset(d, 0, sizeof(d));
        for (int i = 0; i < len; i++)
        {
            int k = s[i] - 'a';
            if (d[k])
            {
                ans = max(ans, i - t);
                t = c[k] + 1;
                memset(d, 0, sizeof(d));
                for (int j = t; j < i; j++)
                    d[s[j] - 'a'] = 1;
            }
            d[k] = 1;
            c[k] = i;
        }
        return max(ans, len - t);
    }
};
