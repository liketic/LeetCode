
class Solution {
public:
    string getPermutation(int n, int k) {
        return getPermutation(n, fac(n), k, 0, initialString(n));
    }

    // get initial string 1234...n
    string initialString(int n) {
        stringstream ss;
        for (int i = 1; i <= n; i++)
            ss << i;
        return ss.str();
    }

    string getPermutation(int n, int fc, int k, int st, string s) {
        // if first string, then return s
        if (k == 1) return s;

        fc /= n;

        // pos is the kth number start number position
        int pos, last;
        if (k % fc == 0) {
            pos = k / fc;
            last = fc;
        } else {
            pos = k / fc + 1;
            last = k % fc;
        }

        // swap
        char c = s[pos + st - 1];
        for (int i = pos + st - 1; i > st; i--) {
            s[i] = s[i - 1];
        }
        s[st] = c;

        return getPermutation(n - 1, fc, last, st + 1, s);
    }

    int fac(int n) {
        int t = 1;
        for (int j = 2; j <= n; j++) {
            t *= j;
        }
        return t;
    }
};
