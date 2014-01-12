class Solution {
public:
    int romanToInt(string s) {
        
        int t = 0, ans = 0;
        
        for (int i = 0; i < s.length(); i++)
            if (s[i] == 'M')
                t++;
            else break;
        s = s.substr(t, s.length() - t);
        ans += 1000 * t;
    
        if (s != "" && (s[0] == 'C' || s[0] == 'D')) {
            t = 0;
            if (s[0] == 'C') { 
                for (int i = 0; i < s.length(); i++)
                    if (s[i] == 'C')
                        t++;
                    else break;
                s = s.substr(t, s.length() - t);
                if (s == "") {
                    ans += t * 100;
                }
                else if (s[0] == 'M' || s[0] == 'D') {
                    if (s[0] == 'M')
                       ans += 900;
                    else ans += 400;
                    s = s.substr(1, s.length() - 1);
                } else {
                    ans += t * 100;
                }
            }
            else {
                s = s.substr(1, s.length() - t);
                for (int j = 0; j < s.length(); j++)
                    if (s[j] == 'C')
                        t++;
                    else break;
                ans += 500 + 100 * t;
                s = s.substr(t, s.length() - t);
            }
        }
        if (s != "" && (s[0] == 'X' || s[0] == 'L'))
        {
            t = 0;
            if (s[0] == 'X') {
                for (int j = 0; j < s.length(); j++)
                    if (s[j] == 'X')
                        t++;
                    else break;
                s = s.substr(t, s.length() - t);
                if (s == "") {
                    ans += 10 * t;
                } else if (s[0] == 'L' || s[0] == 'C'){
                    if (s[0] == 'L') 
                        ans += 40;
                    else ans += 90;
                    s = s.substr(1, s.length() - 1);
                } else {
                    ans += 10 * t;
                }
            }
            else {
                s = s.substr(1, s.length() - 1);
                for (int j = 0; j < s.length(); j++)
                    if (s[j] == 'X')
                        t++;
                    else break;
                ans += 50 + t * 10;
                s = s.substr(t, s.length() - t);
            }
        }
        if (s != "" && (s[0] == 'I' || s[0] == 'V'))
        {
            t = 0;
            if (s[0] == 'I') {
                for (int j = 0; j < s.length(); j++)
                    if (s[j] == 'I')
                        t++;
                    else break;
                s = s.substr(t, s.length() - 1);
                if (s == "") {
                    ans += t;
                }
                else if (s[0] == 'V' || s[0] == 'X') {

                    if (s[0] == 'V')
                        ans += 4;
                    else ans += 9;
                }
                else {
                    ans += t;
                }
            }
            else {
                s = s.substr(1, s.length() - 1);
                for (int j = 0; j < s.length(); j++)
                    if (s[j] == 'I')
                        t++;
                    else break;
                ans += t + 5;
            }
        }
        
        return ans;
    }
};
