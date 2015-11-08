class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int lenOfS = s.length();
        int lenOfT = t.length();

        if (lenOfS != lenOfT) {
            return false;
        }
        map<char, char> m1, m2;
        map<char, char>::iterator it1, it2;

        for (int i = 0; i < lenOfS; i++) {
            it1 = m1.find(s[i]);
            it2 = m2.find(t[i]);

            if (it1 == m1.end() && it2 == m2.end()) {
                m1[s[i]] = t[i];
                m2[t[i]] = s[i];
            } else {
                if (it1->second != t[i] || it2->second != s[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};
