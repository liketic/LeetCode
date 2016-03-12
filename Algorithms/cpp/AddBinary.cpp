class Solution {
public:
    string addBinary(string a, string b) {
        int lenOfA = a.length();
        int lenOfB = b.length();

        // we can assume b is the shorter string
        // if not, swap them first
        if (lenOfA < lenOfB) {
            string s = a;
            a = b;
            b = s;
            lenOfA = a.length();
            lenOfB = b.length();
        }

        for (int i = lenOfA - 1, j = lenOfB - 1;
                i >= 0 && j >= 0;
                i--, j--) {
            a[i] += b[j] - '0';
        }

        for (int i = lenOfA - 1; i > 0; i--) {
            if (a[i] > '1') {
                a[i] = '0' + (a[i] - '0') % 2;
                a[i - 1]++;
            }
        }
        if (a[0] > '1') {
            a[0] = '0' + (a[0] - '0') % 2;
            a = "1" + a;
        }
        return a;
    }
};
