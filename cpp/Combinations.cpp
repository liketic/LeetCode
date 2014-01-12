class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector <vector <int> > ans;
        
        for (int i = 0; i < (1 << n); i++) {
            int t = 0;
            for (int j = 0; j < n; j++)
                if (i & (1 << j))
                    t++;
            if (t == k) {
                vector <int> x;
                for (int j = 0; j < n; j++)
                    if (i & (1 << j))
                        x.push_back(j + 1);
                ans.push_back(x);
            }
        }
        return ans;
     }
};

