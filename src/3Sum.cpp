class Solution
{
public:
    vector<vector<int> > threeSum(vector<int> &num)
    {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int n = num.size();
        sort(num.begin(), num.end());

        vector< vector<int> > ans;

        for (int i = 0; i < n; i++)
        {

            if (i && num[i] == num[i - 1])
                continue;
            for (int j = i + 1; j < n; j++)
            {
                if (j > i + 1 && num[j] == num[j - 1])
                    continue;
                int t = num[i] + num[j];
                t *= -1;
                int l1 = j + 1, r1 = n - 1;
                while (l1 <= r1)
                {
                    int m = (l1 + r1) / 2;
                    if (num[m] == t)
                    {
                        vector<int> x;
                        x.push_back(num[i]);
                        x.push_back(num[j]);
                        x.push_back(num[m]);
                        ans.push_back(x);
                        break;
                    }
                    else if (num[m] < t)
                    {
                        l1 = m + 1;
                    }
                    else
                    {
                        r1 = m - 1;
                    }
                }
            }
        }
        return ans;
    }
};
