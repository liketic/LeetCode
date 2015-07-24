
struct node{
    int v, i;
};

bool cmp(const node& a, const node& b) {
    if (a.v == b.v) return a.i < b.i;
    return a.v < b.v;
}

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        //sort(numbers.begin(), numbers.end());
        int n = numbers.size();
        node d[n];
        for (int i = 0; i < n; i++) {
            d[i].i = i + 1;
            d[i].v = numbers[i];
        }
        sort(d, d + n, cmp);
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int v = target - d[i].v;
            int l = i + 1, r = n - 1, m;
            while (l <= r) {
                m = (l + r) / 2;
                if (d[m].v == v) {
                    ans.push_back(min(d[i].i, d[m].i));
                    ans.push_back(max(d[i].i, d[m].i));
                    return ans;
                }
                if (d[m].v > v) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
        }
        return ans;
    }
};
