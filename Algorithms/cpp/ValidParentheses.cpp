//#include <iostream>
//
//using namespace std;

const int MAX_SIZE = 10005;

class Solution {
private:
    char st[MAX_SIZE];

    bool rightTo(char a, char b) {
        if (b == '(') return ')' == a;
        if (b == '[') return ']' == a;
        if (b == '{') return '}' == a;
        return false;
    }
public:
    bool isValid(string s) {
        int t = 0;
        int lenOfs = s.length();

        for (int i = 0; i < lenOfs; i++) {
            if (t == 0 || !rightTo(s[i], st[t - 1])) {
                st[t++] = s[i];
            } else {
                t--;
            }
        }
        return t == 0;
    }
};

//int main() {
//
//   Solution s;
//
//    cout << s.isValid("()[]{}") << endl;
//    cout << s.isValid("(]") << endl;
//    cout << s.isValid("([)]") << endl;
//}
