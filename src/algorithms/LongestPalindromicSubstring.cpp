class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length(), l;
        string ans;
        for (int i = 0; i < n; i++)
        {
            for (int j = i, k = i; j >= 0 && k < n; k++, j--)
                if (s[j] != s[k])
                    break;
                else
                {
                    if (l < k - j + 1)
                    {
                        l = k - j + 1;
                        ans = s.substr(j, l);
                    }
                }
            for (int j = i, k = i + 1; j >= 0 && k < n; k++, j--)
                if (s[j] != s[k])
                    break;
                else
                {
                    if (l < k - j + 1)
                    {
                        l = k - j + 1;
                        ans = s.substr(j, l);
                    }
                }
        }
        return ans;
    }
};
