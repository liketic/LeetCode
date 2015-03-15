class Solution
{
public:
    double pow(double x, int n)
    {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (!n)
            return 1;
        if (x == 0)
            return 0;
        if (n < 0)
        {
            n *= -1;
            x = 1 / x;
        }
        double temp = pow(x, n / 2);
        if (n & 1)
            return temp * temp * x;
        else
            return temp * temp;
    }
};
