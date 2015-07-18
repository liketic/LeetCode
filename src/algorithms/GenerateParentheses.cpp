struct node {
    string s;
    int lc;
    int rc;
};

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        queue<node> q;
        node first;
        first.s = "(";
        first.lc = 1;
        first.rc = 0;

        q.push(first);

        node cur;
        vector<string> ans;

        while (!q.empty()) {

            cur = q.front();
            q.pop();

            if (cur.lc == n) {
                string t = cur.s;
                while (t.length() < n * 2) {
                    t += ")";
                }
                ans.push_back(t);
            } else {
                node a;
                a.s = cur.s + "(";
                a.lc = cur.lc + 1;
                a.rc = cur.rc;
                q.push(a);

                if (cur.rc < cur.lc) {
                    node b;
                    b.s = cur.s += ")";
                    b.lc = cur.lc;
                    b.rc = cur.rc + 1;
                    q.push(b);
                }
            }
        }
        return ans;
    }
};
