class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sum = 0;
        int startIndex = 0;

        for (int i = 0; i < 2 * n; i++) {
            sum += gas[i % n] - cost[i % n];
            if (sum < 0) {
                sum = 0;
                startIndex = i + 1;
            }
            else {
                if (i - startIndex + 1 == n) return startIndex;
            }
        }

        return -1;
    }
};
