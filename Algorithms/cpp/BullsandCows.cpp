class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        int a[10], b[10];
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));

        int n = secret.length();

        for (int i = 0; i < n; i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                a[secret[i] - '0']++;
                b[guess[i] - '0']++;
            }
        }
        string ans = "";
        ans += toString(bulls) + "A";
        for (int i = 0; i < 10; i++) {
            cows += min(a[i], b[i]);
        }
        ans += toString(cows) + "B";
        return ans;
    }

    string toString(int a) {
        stringstream strStream;
        strStream << a;
        return strStream.str();
    }
};
