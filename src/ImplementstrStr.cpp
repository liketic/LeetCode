#include <iostream>
#include <string.h>
using namespace std;

//max size of haystack
const int N = 100005;


class Solution
{
private:
    int next[N];

    void Cal_Next(char str[], int next[], int str_len)
    {
        next[0] = -1;
        int j = next[0];
        for (int i = 1; i < str_len; i++)
        {
            while (j >= 0 && str[i] != str[j + 1])
            {
                j = next[j];
            }
            if (str[i] == str[j + 1])
                j++;
            next[i] = j;
        }
    }


    int KMP(char main_str[], char sub_str[], int next[])
    {
        int main_len = strlen(main_str);
        int sub_len = strlen(sub_str);
        Cal_Next(sub_str, next, sub_len);
        int j = next[0];

        for (int i = 0; i < main_len; i++)
        {
            while (j >= 0 && main_str[i] != sub_str[j + 1])
            {
                j = next[j];
            }
            if (main_str[i] == sub_str[j + 1])
                j++;
            if (j == sub_len - 1)
            {
                //find it
                return (i - sub_len + 1);
                //j=next[j];
            }
        }
        return -1;
    }
public:
    int strStr(char *haystack, char *needle)
    {
        int lenn = strlen(needle);
        if (!lenn)   // if needle is "" then kmp is not right
        {
            return 0;
        }
        return KMP(haystack, needle, next);
    }
};


int main()
{

    Solution s;

    char *a = "abcddef";
    char *b = "cd";

    cout << s.strStr(a, b) << endl;
}

