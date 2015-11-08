class Solution {
private:
    static string toStr(int n) {
        stringstream ss;
        ss << n;
        return ss.str();
    }

public:
    string convertToTitle(int n) {
        string ret = "";

        while (n) {
            n--;
            int temp = n % 26;
            ret = toStr(temp) + ret;
            n /= 26;
        }

        return ret;
    }
};
