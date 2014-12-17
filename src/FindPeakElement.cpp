

class Solution
{
public:
    int findPeakElement(const vector<int> &num)
    {
        for (int i = 0; i < num.size(); i++)
        {
            if ((i == 0 || num[i] > num[i - 1]) && (i == num.size() - 1 || num[i] > num[i + 1]))
            {
                return i;
            }
        }
    }
};
