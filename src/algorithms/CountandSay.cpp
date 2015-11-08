class Solution {
public:
    string to(int a, char b) {
        char c[10];
        int k = 0;
        while (a) {
            c[k++] = (a % 10) + '0';
            a /= 10;
        }
        for (int i = 0; i < k / 2; i++) {
            char t = c[i];
            c[i] = c[k - i - 1];
            c[k - i - 1] = t;
        }
        c[k++] = b;
        c[k] = '\0';
        return string(c);
    }
    string change(string s) {
        int l = s.length(), x = 0;
        string t = "";
        for (int i = 0; i < l; i++) {
            x++;
            if (i == l - 1 || s[i] != s[i + 1]) {
                t += to(x, s[i]);
                x = 0;
            }
        }
        return t;
    }
    string countAndSay(int n) {
        string s = "1";
        for (int i = 2; i <= n; i++) {
            s = change(s);
        }
        return s;
    }
};
