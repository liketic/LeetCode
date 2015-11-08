//#include <iostream>
//
//using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        int len = s.length();

        if (nRows == 1) {
            return s;
        }

        char *ret = new char[len + 1];
        int p = 0;

        //a round
        int round = 2 * nRows  - 2;

        for (int i = 0; i < nRows; i++) {
            for (int j = 0; j < len + i; j += round) {

                if (j - i >= 0 && s[j - i] != '_') {
                    ret[p++] = s[j - i];
                    s[j - i] = '_';
                }

                if (j + i < len && s[j + i] != '_') {
                    ret[p++] = s[j + i];
                    s[j + i] = '_';
                }
            }
        }
        ret[p] = '\0';
        return string(ret);
    }
};

//int main()
//{
//
//    Solution s;
//    cout << s.convert("PAYPALISHIRING", 3) <<endl;
//    cout << s.convert("ABCD", 3) << endl;
//    return 0;
//}
