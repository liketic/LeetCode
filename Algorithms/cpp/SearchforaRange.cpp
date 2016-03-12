class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int l1 = 0, r1 = n - 1;
        while (l1 <= r1) {
            int m = (l1 + r1) / 2;
            if (A[m] >= target)
                r1 = m - 1;
            else l1 = m + 1;
        }

        int l2 = 0, r2 = n - 1;
        while (l2 <= r2) {
            int m = (l2 + r2) / 2;
            if (A[m] <= target)
                l2 = m + 1;
            else r2 = m - 1;
        }
        vector<int> ans;
        if (!(l1 < n && l1 >= 0 && A[l1] == target))
            l1 = r2 = -1;
        ans.push_back(l1);
        ans.push_back(r2);
        return ans;
    }
};
