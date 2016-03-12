class NumArray {
public:
    NumArray(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum.push_back(nums[i]);
            if (i) {
                sum[i] += sum[i - 1];
            }
        }
    }

    int sumRange(int i, int j) {
        return i > 0 ? (sum[j] - sum[i - 1]) : sum[j];
    }
private:
    vector<int> sum;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
