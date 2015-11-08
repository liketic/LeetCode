const long long MAX_INT_VALUE = 2147483647LL;
const long long MIN_INT_VALUE = -2147483648LL;

class Solution {
public:
    int myAtoi(const string& str) {
        int len = str.length();
        if (len == 0)
            return 0;
        long long ans = 0, i = 0, j = 1;

        while (i < len && !isalnum(str[i])
                && str[i] != '+' && str[i] != '-')
            ++i;
        if (str[i] == '-' || str[i] == '+') {
            j = str[i] == '-' ? -1 : 1;
            ++i;
        }
        for (; str[i] && isdigit(str[i]); i++) {
            ans = ans * 10 + (str[i] - '0');
            if (ans > MAX_INT_VALUE) break;
        }
        ans *= j;
        ans = min(ans, MAX_INT_VALUE);
        ans = max(ans, MIN_INT_VALUE);
        return ans;
    }
};
