#include <iostream>
#include <string.h>
using namespace std;

//max size of haystack
const int MAX_SIZE = 100005;


class Solution {
private:
    int next[MAX_SIZE];

    void calNext(const string& str, int next[], int strLen) {
        next[0] = -1;
        int j = next[0];
        for (int i = 1; i < strLen; i++) {
            while (j >= 0 && str[i] != str[j + 1]) {
                j = next[j];
            }
            if (str[i] == str[j + 1])
                j++;
            next[i] = j;
        }
    }

    int KMP(const string& mainStr, const string& subStr, int next[]) {
        int lenOfMain = mainStr.length();
        int lenOfSub = subStr.length();

        calNext(subStr, next, lenOfSub);
        int j = next[0];

        for (int i = 0; i < lenOfMain; i++) {
            while (j >= 0 && mainStr[i] != subStr[j + 1]) {
                j = next[j];
            }
            if (mainStr[i] == subStr[j + 1])
                j++;
            if (j == lenOfSub - 1) {
                //find it
                return (i - lenOfSub + 1);
            }
        }
        return -1;
    }
public:
    int strStr(string haystack, string needle) {
        int lenOfNeedle = needle.length();
        if (!lenOfNeedle) { // if needle is "" then kmp is not right
            return 0;
        }
        return KMP(haystack, needle, next);
    }
};


int main() {

    Solution s;

    char *a = "abcddef";
    char *b = "cd";

    cout << s.strStr(a, b) << endl;
}

