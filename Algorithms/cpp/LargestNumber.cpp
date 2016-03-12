#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    static bool cmp(int a, int b) {
        string x, y;
        stringstream ss;
        ss << a;
        ss >> x;
        ss.str("");
        ss.clear();
        ss << b;
        ss >> y;
        return (x + y) > (y + x);
    }
public:
    string largestNumber(vector<int> &num) {
        string ret = "";
        sort(num.begin(), num.end(), cmp);

        int sizeOfNum = num.size();

        for (int i = 0; i < sizeOfNum; i++) {
            stringstream ss;
            ss << num[i];
            ret += ss.str();
        }
        int pos = 0;
        int sizeOfRet = ret.size();

        while (pos < sizeOfRet - 1 && ret[pos] == '0') {
            ++pos;
        }
        return ret.substr(pos, sizeOfRet - pos);
    }
};
