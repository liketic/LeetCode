class Solution {
public:
    int calculate(const string& s) {
        return calculate(s, 0, s.length() - 1);
    }

private:
    int calculate(const string &s, int l, int r) {
        vector<int> arr;
        vector<char> op;

        for (int i = l; i <= r; i++) {
            if (s[i] == '(') {
                int t = 1;
                for (int j = i + 1; j <= r; j++) {
                    if (s[j] == '(')t++;
                    else if (s[j] == ')') {
                        t--;
                        if (t == 0) {
                            int r = calculate(s, i + 1, j - 1);
                            arr.push_back(r);
                            i = j;
                            break;
                        }
                    }
                }
            } else if (isPlusOrMinus(s[i])) {
                op.push_back(s[i]);
            } else if (isNumber(s[i])) {
                int j = i + 1;
                for (; j <= r; j++) {
                    if (!isNumber(s[j])) break;
                }
                int t = toInt(s, i, j);
                i = j - 1;
                arr.push_back(t);
            }
        }
        int ans = arr[0];
        for (int i = 0; i < op.size(); i++) {
            if (op[i] == '+')
                ans += arr[i + 1];
            else ans -= arr[i + 1];
        }
        return ans;
    }

    static int toInt(const string& s, int l, int r) {
        int ans = 0;
        for (int i = l; i < r; i++) {
            ans = ans * 10 + (s[i] - '0');
        }
        return ans;
    }

    static bool isPlusOrMinus(const char& s) {
        return (s == '-' || s == '+');
    }

    static bool isNumber(char c) {
        return (c >= '0' && c <= '9');
    }
};
