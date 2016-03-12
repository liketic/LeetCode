class Solution {
private:
    static int getMin(vector<int> arr, int l, int r) {
        if (l == r || arr[l] < arr[r]) {
            return arr[l];
        }
        int m = (l + r) / 2;
        return min(getMin(arr, l, m), getMin(arr, m + 1, r));
    }

public:
    int findMin(vector<int> &num) {
        return getMin(num, 0, num.size() - 1);
    }
};
