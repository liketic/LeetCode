class Solution {
public:

    string strmul(string s, int t) {
        string ans = "";
        for (int i = 0; i < t; i++)
            ans += s;
        return ans;
    }

    string intToRoman(int num) {
        string ans = "";
        int t = num % 10;
        num /= 10;
        if (t <= 3)
            ans += strmul("I", t);
        else if (t < 5)
            ans += "IV";
        else if (t <= 8)
            ans += "V" + strmul("I", t - 5);
        else ans += "IX";

        t = num % 10;
        num /= 10;

        if (t <= 3)
            ans = strmul("X", t) + ans;
        else if (t < 5)
            ans = "XL" + ans;
        else if (t <= 8)
            ans = "L" + strmul("X", t - 5) + ans;
        else ans = "XC" + ans;

        t = num % 10;
        num /= 10;

        if (t <= 3)
            ans = strmul("C", t) + ans;
        else if (t < 5)
            ans = "CD" + ans;
        else if (t <= 8)
            ans = "D" + strmul("C", t - 5) + ans;
        else ans = "CM" + ans;

        ans = strmul("M", num) + ans;
        return ans;
    }
};
