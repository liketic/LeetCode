class Solution {
private:
    void reverse(int a[], int n) {
        int temp;
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
public:
    void rotate(int nums[], int n, int k) {
        k %= n;
        reverse(nums, n);
        reverse(nums, k);
        reverse(nums + k, n - k);
    }
};

