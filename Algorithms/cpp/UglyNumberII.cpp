class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long>> que;
        que.push(1L);
        long long t = 1, curr;

        while (t++ < n) {
            curr = que.top();
            while (!que.empty() && curr == que.top()) {
                que.pop();
            }
            que.push(curr * 2);
            que.push(curr * 3);
            que.push(curr * 5);
        }
        int ans = (int)que.top();
        while (!que.empty()) {
            que.pop();
        }
        return ans;
    }
};
