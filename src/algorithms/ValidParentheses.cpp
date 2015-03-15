//#include <iostream>
//
//using namespace std;

class Solution
{
private:
    char st[10005];
    int t = 0;

    bool rightTo(char a, char b)
    {
        if (b == '(') return ')' == a;
        if (b == '[') return ']' == a;
        if (b == '{') return '}' == a;
        return 0;
    }
public:
    bool isValid(string s)
    {
        t = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (t == 0 || !rightTo(s[i], st[t - 1]))
            {
                st[t++] = s[i];
            }
            else
            {
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
