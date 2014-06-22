class Solution {
public:
    int numTrees(int n) {
        vector <int> x;
        x.push_back(1);
        
        for (int i = 1; i <= n; i++) {
            int t = 0;
            for (int j = 1; j <= i; j++)
                t += x[i - j] * x[j - 1];
            x.push_back(t);
        }
        return x[n];
    }
};
