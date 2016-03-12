class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> ss = splitStringToArray(str);
        int sizeOfss = ss.size();
        int lenOfPattern = pattern.length();

        if (sizeOfss != lenOfPattern) {
            return false;
        }
        for (int i = 0; i < lenOfPattern; i++) {
            for (int j = 0; j < i; j++) {
                if (pattern[i] == pattern[j] && ss[i] != ss[j]) {
                    return false;
                }
                if (ss[i] == ss[j] && pattern[i] != pattern[j]) {
                    return false;
                }
            }
        }
        return true;
    }
private:
    static vector<string> splitStringToArray(const string& str) {
        int pos = 0;
        vector<string> vets;
        int lenOfStr = str.length();

        for (int i = 0; i < lenOfStr; i++) {
            if (i == lenOfStr - 1 || str[i + 1] == ' ') {
                string s = str.substr(pos, i - pos + 1);
                vets.push_back(s);
                pos = i + 2;
            }
        }
        return vets;
    }
};
