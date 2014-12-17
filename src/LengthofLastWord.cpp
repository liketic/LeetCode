class Solution
{
public:
    int lengthOfLastWord(const char *s)
    {
        int len = 0;
        while (s[len] != '\0')len++;
        len--;
        while (len >= 0 && !isalpha(s[len]))len--;
        if (len == -1)
            return 0;
        for (int i = len; i >= 0; i--)
            if (!(isalpha(s[i])))
                return len - i;
        return len + 1;
    }
};
