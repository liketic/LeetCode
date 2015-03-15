class Solution
{
public:
    string addBinary(string a, string b)
    {
        if (a.length() < b.length())
        {
            string s = a;
            a = b;
            b = s;
        }
        for (int i = a.length() - 1, j = b.length() - 1; i >= 0 && j >= 0; i--, j--)
        {
            a[i] += b[j] - '0';
        }
        for (int i = a.length() - 1; i > 0; i--)
        {
            if (a[i] > '1')
            {
                a[i] = '0' + (a[i] - '0') % 2;
                a[i - 1]++;
            }
        }
        if (a[0] > '1')
        {
            a[0] = '0' + (a[0] - '0') % 2;
            a = "1" + a;
        }
        return a;
    }
};
