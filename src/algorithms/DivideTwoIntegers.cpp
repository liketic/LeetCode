class Solution
{
public:
    int divide(int dividend, int divisor)
    {

        long long d = dividend, di = divisor;

        int f = 1;

        if (dividend < 0)
        {
            d *= -1;
            f *= -1;
        }
        if (divisor < 0)
        {
            di *= -1;
            f *= -1;
        }
        long long l = 0, r = d;

        while (l <= r)
        {
            long long mid = (l + r) / 2;
            if (mid * di > d)
                r = mid - 1;
            else
            {
                l = mid + 1;
            }
        }
        //cout << r << " " << f << endl;
        return r * f;
    }
};
