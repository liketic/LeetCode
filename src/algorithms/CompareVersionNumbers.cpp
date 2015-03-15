#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    vector <string> split(string v)
    {
        int i = 0, len = v.length();
        vector<string> ret;

        for (int j = 0; j < len; j++)
        {
            if (v[j] == '.')
            {
                if (j > i)
                {
                    ret.push_back(v.substr(i, j - i));
                }
                i = j + 1;
            }
            else if (j == len - 1)
            {
                ret.push_back(v.substr(i, j - i + 1));
            }
        }
        return ret;
    }

    int compare(string a, string b)
    {
        int i = 0, j = 0;
        int lena = a.length(), lenb = b.length();

        while (i < lena && a[i] == '0')
        {
            i++;
        }
        while (j < lenb && b[j] == '0')
        {
            j++;
        }
        if (lena - i != lenb - j)
        {
            return (lena - i > lenb - j ? 1 : -1);
        }
        for (; i < lena, j < lenb; i++, j++)
        {
            if (a[i] != b[j])
            {
                return (a[i] > b[j] ? 1 : -1);
            }
        }
        return 0;
    }

    bool isAllZero(string v)
    {
        int l = v.length();
        for (int i = 0; i < l; i++)
        {
            if (v[i] != '0')
            {
                return false;
            }
        }
        return true;
    }
public:
    int compareVersion(string version1, string version2)
    {
        vector<string> arrA = split(version1);
        vector<string> arrB = split(version2);

        for (int i = 0; i < arrA.size() && i < arrB.size(); i++)
        {
            int t = compare(arrA[i], arrB[i]);
            if (t)
            {
                return t;
            }
        }
        if (arrA.size() < arrB.size())
        {
            for (int j = arrA.size(); j < arrB.size(); j++)
            {
                if (!isAllZero(arrB[j]))
                {
                    return -1;
                }
            }
            return 0;
        }
        else if (arrA.size() > arrB.size())
        {
            for (int j = arrB.size(); j < arrA.size(); j++)
            {
                if (!isAllZero(arrA[j]))
                {
                    return 1;
                }
            }
            return 0;
        }
        else
        {
            return 0;
        }
    }
};


//int main()
//{
//    string v1 = "01", v2 = "1";
//    Solution s;
//
//    cout << s.compareVersion(v1, v2) << endl;
//    return 0;
//}


