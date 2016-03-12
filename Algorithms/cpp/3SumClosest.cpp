iclass Solution {
public:
    int threeSumClosest(vector<int> &a, int s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int n = a.size();
        sort(a.begin(), a.end());

        int ans = 10000000;
        int ret = 0;

        for (int i = 0; i < n; i++) {
            if (i && a[i] == a[i - 1])
                continue;
            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && a[j] == a[j - 1])
                    continue;
                int l = j + 1, r = n - 1;
                int temp = s  - a[i] - a[j];

                while (l <= r) {
                    int m = (l + r) / 2;
                    if (a[m] == temp) {
                        return s;
                    } else if (a[m] > temp) {
                        r = m - 1;
                    } else {
                        l = m + 1;
                    }
                }
                for (int k = r; k <= l; k++) {
                    if (k > j && k < n) {
                        if (ans > abs(temp - a[k])) {
                            ans = abs(temp - a[k]);
                            ret = a[i] + a[j] + a[k];
                        }
                    }
                }
            }
        }

        return ret;
    }
};
