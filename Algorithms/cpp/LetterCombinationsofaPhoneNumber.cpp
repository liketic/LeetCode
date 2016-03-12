class Solution {
public:
    vector<string> change(char dig) {
        vector<string> ans;
        switch(dig - '0') {
        case 0:
            ans.push_back(" ");
            break;
        case 1:
            break;
        case 2:
            ans.push_back("a");
            ans.push_back("b");
            ans.push_back("c");
            break;
        case 3:
            ans.push_back("d");
            ans.push_back("e");
            ans.push_back("f");
            break;
        case 4:
            ans.push_back("g");
            ans.push_back("h");
            ans.push_back("i");
            break;
        case 5:
            ans.push_back("j");
            ans.push_back("k");
            ans.push_back("l");
            break;
        case 6:
            ans.push_back("m");
            ans.push_back("n");
            ans.push_back("o");
            break;
        case 7:
            ans.push_back("p");
            ans.push_back("q");
            ans.push_back("r");
            ans.push_back("s");
            break;
        case 8:
            ans.push_back("t");
            ans.push_back("u");
            ans.push_back("v");
            break;
        case 9:
            ans.push_back("w");
            ans.push_back("x");
            ans.push_back("y");
            ans.push_back("z");
            break;
        }
        return ans;
    }
    vector<string> letterCombinations(string digits) {
        int len = digits.length();
        vector<string> s, t;
        if (digits == "") {
            s.push_back("");
            return s;
        }

        for (int i = 0; i < len; i++) {
            vector <string> x = change(digits[i]);
            int n = x.size();
            if (i == 0)
                for (int j = 0; j < n; j++)
                    s.push_back(x[j]);
            else {
                int m = s.size();
                for (int j = 0; j < n; j++)
                    for (int k = 0; k < m; k++)
                        t.push_back(s[k] + x[j]);
                s = t;
                t.clear();
            }
        }
        return s;
    }
};

