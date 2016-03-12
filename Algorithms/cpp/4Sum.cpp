
const int MAX_SIZE = 1000005;
struct node {
    int v;
    int x, y;
};

node d[MAX_SIZE];

bool cmp(const node& a, const node& b) {
    if (a.v != b.v)
        return a.v < b.v;
    if (a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                d[k].v = nums[i] + nums[j];
                d[k].x = i;
                d[k++].y = j;
            }
        }
        sort(d, d + k, cmp);
        vector<vector<int> > ans;
        for (int i = 0; i < k; i++) {
            int temp = target - d[i].v;
            int l = i + 1, r = k - 1;

            while (l <= r) {
                int m = (l + r) / 2;
                if (d[m].v == temp) {
                    int j = m;
                    while (j >= 0 && d[j].v == temp)j--;
                    j++;
                    for (; j < k; j++) {
                        if (d[j].v != temp) break;
                        if (d[j].x != d[i].x && d[j].x != d[i].y
                                && d[j].y != d[i].x && d[j].y != d[i].y) {
                            vector<int> item;
                            item.push_back(nums[d[i].x]);
                            item.push_back(nums[d[i].y]);
                            item.push_back(nums[d[j].x]);
                            item.push_back(nums[d[j].y]);
                            sort(item.begin(), item.end());
                            ans.push_back(item);
                        }
                    }
                    break;
                } else if (d[m].v > temp) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
        }
        vector<vector<int> > ans2;
        int sizeofans = ans.size();
        for (int i = 0; i < sizeofans; i++) {
            bool has = false;
            for (int j = 0; j < ans2.size(); j++) {
                if (isEqual(ans[i], ans2[j])) {
                    has = true;
                    break;
                }
            }
            if (!has) {
                ans2.push_back(ans[i]);
            }
        }
        return ans2;
    }
private:
    bool isEqual(vector<int>& a, vector<int>& b) {
        for (int i = 0; i < 4; i++) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }
};
