// define index size
const int MAX_INDEX_SIZE = 26;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[MAX_INDEX_SIZE];

        memset(count, 0, sizeof(count));
        for (int i = 0; i < s.length(); i++)
            count[s[i] - 'a']++;
        for (int i = 0; i < t.length(); i++)
            count[t[i] - 'a']--;
        for (int i = 0; i < MAX_INDEX_SIZE; i++)
            if (count[i]) return false;
        return true;
    }
};
