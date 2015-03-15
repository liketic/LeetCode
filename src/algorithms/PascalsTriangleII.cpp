class Solution
{
public:
    vector<int> getRow(int r)
    {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> a, b;
        r++;

        for (int i = 0; i < r; i++)
        {
            b.clear();
            for (int j = 0; j <= i; j++)
            {
                if (j == 0 || j == i)
                    b.push_back(1);
                else
                {
                    b.push_back(a[j - 1] + a[j]);
                }
            }
            a.clear();
            for (int j = 0; j <= i; j++)
                a.push_back(b[j]);
        }
        return a;
    }
};
