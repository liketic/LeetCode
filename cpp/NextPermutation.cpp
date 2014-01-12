class Solution {
public:
    bool isSorted(vector<int> &a, int n) {
        for (int i = 0; i < n - 1; i++)
            if (a[i] < a[i + 1])
                return 0;
        return 1;
    }

    void nextPermutation(vector<int> &num) {
        int n = num.size();
        if (isSorted(num, n)) {
            sort(num.begin(), num.end());
        } else {
            for (int i = n - 2; i >= 0; i--)
                if (num[i] < num[i + 1]) {
                    int k = i + 1, m = num[i + 1];
                    for (int j = i + 1; j < n; j++)
                        if (num[j] > num[i] && num[j] < m) {
                            m = num[j];
                            k = j;
                        }
                    int t = num[i];
                    num[i] = num[k];
                    num[k] = t;
                    std::sort(num.begin() + i + 1, num.end());
                    break;
                }
        }
    }
};
