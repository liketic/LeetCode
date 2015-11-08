class Solution {
public:
    vector<int> diffWaysToCompute(string input) {

        vector<int> nums;
        vector<char> ccs;
        int start = 0;
        int lenOfInput = input.length();

        for (int i = 0; i < lenOfInput; i++) {
            if (isOp(input[i])) {
                ccs.push_back(input[i]);
            }
            if (i == lenOfInput - 1 || isOp(input[i + 1])) {
                int t = 0;
                for (int j = start; j <= i; j++) {
                    t = t * 10 + input[j] - '0';
                }
                start = i + 2;
                nums.push_back(t);
            }
        }
        return compute(nums, ccs);
    }


private:
    vector<int> compute(vector<int>& num, vector<char>& ops) {
        vector<int> ans;
        int sizeOfNum = num.size();
        int sizeOfOps = ops.size();

        if (sizeOfNum == 1) {
            ans.push_back(num[0]);
            return ans;
        }

        for (int i = 0; i < sizeOfOps; i++) {

            vector<int> tt1, tt2;
            vector<char> cc1, cc2;

            for (int j = 0; j <= i; j++) {
                tt1.push_back(num[j]);
                if (j < i) {
                    cc1.push_back(ops[j]);
                }
            }
            for (int j = i + 1; j < sizeOfNum; j++) {
                tt2.push_back(num[j]);
                if (j < sizeOfOps) {
                    cc2.push_back(ops[j]);
                }
            }
            vector<int> a = compute(tt1, cc1);
            vector<int> b = compute(tt2, cc2);
            int sizeOfA = a.size();
            int sizeOfB = b.size();

            for (int x = 0; x < sizeOfA; x++) {
                for (int y = 0; y < sizeOfB; y++) {
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
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        }
    }
};
