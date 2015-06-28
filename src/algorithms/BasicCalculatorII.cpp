class Solution {
public:
    int calculate(string s) {
        vector<string> numberAndOps = this->split(s);
        int n = numberAndOps.size();
        int* d = new int[n];
        char* c = new char[n];
        int p = 0;
        int q = 0;
        for (int i = 0; i < n; i++) {
            if (isMultiOrDivide(numberAndOps[i])) {
                int op1 = d[p - 1];
                int op2 = toInt(numberAndOps[i + 1]);
                if (numberAndOps[i] == "/") {
                    d[p - 1] = op1 / op2;
                } else {
                    d[p - 1] = op1 * op2;
                }
                i++;
            } else if (isPlusOrMinus(numberAndOps[i])){
                c[q++] = numberAndOps[i][0];
            } else {
                d[p++] = toInt(numberAndOps[i]);
            }
        }
        int ans = d[0];
        for (int i = 0; i < q; i++) {
            if (c[i] == '+') {
                ans += d[i + 1];
            } else {
                ans -= d[i + 1];
            }
        }
        return ans;
    }
private:
    vector<string> split(const string& s) {
        vector<string> ans;
        int n = s.length();
        for (int i = 0; i < n;) {
            if (isNumber(s[i])) {
                int j = i + 1;
                for (; j < n; j++) {
                    if (!isNumber(s[j])) {
                        break;
                    }
                }
                ans.push_back(s.substr(i, j - i));
                i = j;
            } else if (isOperator(s[i])) {
                ans.push_back(s.substr(i, 1));
                i++;
            } else {
                i++;
            }
        }
        return ans;
    }

    static int toInt(const string& s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            ans = ans * 10 + (s[i] - '0');
        }
        return ans;
    }

    static bool isMultiOrDivide(const string& s) {
        return (s == "/" || s == "*");
    }

    static bool isPlusOrMinus(const string& s) {
        return (s == "-" || s == "+");
    }

    static bool isNumber(char c) {
        return (c >= '0' && c <= '9');
    }

    static bool isOperator(char c) {
        return (c == '/' || c == '*' || c == '+' || c == '-');
    }
};
