class Solution {
public:
    bool isPalindrome(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int n = s.size();
        for (int i = 0, j = n - 1; i < j; ) {
            if (!((s[i] >= 'a' && s[i] <= 'z')
                  || (s[i] >= 'A' && s[i] <= 'Z')
                  || (s[i] >= '0' && s[i] <= '9'))) {
                i++;
                continue;
            }
            if (!((s[j] >= 'a' && s[j] <= 'z')
                  || (s[j] >= 'A' && s[j] <= 'Z')
                  || (s[j] >= '0' && s[j] <= '9'))) {
                j--;
                continue;
            }
            if (s[i] == s[j]
                || (s[i] - 'a') == (s[j] - 'A')
                || (s[i] - 'A') == (s[j] - 'a')) {
                i++;
                j--;
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
};
