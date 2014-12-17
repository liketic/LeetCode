class Solution
{
public:
    int str2Int(string s)
    {
        int l = s.size(), t = 0;
        int i = 0, j = 1;
        if (s[i] == '+' || s[i] == '-')
        {
            j = s[i] == '-' ? -1 : 1;
            ++i;
        }
        for (; i < l; i++)
            t = t * 10 + s[i] - '0';
        return t * j;
    }
    bool isOper(string s)
    {
        return (s == "/" || s == "+" || s == "-" || s == "*");
    }

    int oper(string op, int a, int b)
    {
        if (op == "/")
            return a / b;
        else if (op == "*")
            return a * b;
        else if (op == "+")
            return a + b;
        else return a - b;
    }

    int evalRPN(vector<string> &tokens)
    {
        stack<int> sta;

        int n = tokens.size();
        for (int i = 0; i < n; i++)
            if (isOper(tokens[i]))
            {
                int y = sta.top();
                sta.pop();
                int x = sta.top();
                sta.pop();
                int t = oper(tokens[i], x, y);
                sta.push(t);
            }
            else
            {
                int t = str2Int(tokens[i]);
                sta.push(t);
            }
        int ans = sta.top();
        sta.pop();
        return ans;
    }
};
