class Solution {
public:
    vector<int> diffWaysToCompute(string input) {

        vector<int> nums;
        vector<char> ccs;
        int start = 0;

        for (int i = 0; i < input.length(); i++) {
            if (isOp(input[i])) {
                ccs.push_back(input[i]);
            }
            if (i == input.length() - 1 || isOp(input[i + 1])) {
                int t = 0;
                for (int j = start; j <= i; j++) {
                    t = t * 10 + input[j] - '0';
                }
                start = i + 2;
                nums.push_back(t);
            }
        }
        return this->compute(nums, ccs);
    }


private:
    vector<int> compute(vector<int> num, vector<char> ops) {
        vector<int> ans;
        if (num.size() == 1) {
            ans.push_back(num[0]);
            return ans;
        }

        for (int i = 0; i < ops.size(); i++) {

            vector<int> tt1, tt2;
            vector<char> cc1, cc2;

            for (int j = 0; j <= i; j++) {
                tt1.push_back(num[j]);
                if (j < i) {
                    cc1.push_back(ops[j]);
                }
            }
            for (int j = i + 1; j < num.size(); j++) {
                tt2.push_back(num[j]);
                if (j < ops.size()) {
                    cc2.push_back(ops[j]);
                }
            }
            vector<int> a = compute(tt1, cc1);
            vector<int> b = compute(tt2, cc2);
            for (int x = 0; x < a.size(); x++) {
                for (int y = 0; y < b.size(); y++) {
                      ans.push_back(calculate(a[x], b[y], ops[i]));
                }
            }

        }
        return ans;
    }

    bool isOp(char oper) {
        return oper == '+' || oper == '-' || oper == '/' || oper == '*';
    }

    int calculate(int a, int b, char oper) {
        switch(oper) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
        }
    }
};
