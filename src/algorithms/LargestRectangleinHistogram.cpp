class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int len = height.size();
        int left[len + 1], right[len + 1];

        for (int i = 1; i <= len; i++) {
            if (i == 1) left[i] = 0;
            else {
                int t = i - 1;
                while (t && height[t - 1] >= height[i - 1]) {
                    t = left[t];
                }
                left[i] = t;
            }
        }

        for (int i = len; i >= 1; i--) {
            if (i == len) right[i] = len + 1;
            else {
                int t = i + 1;
                while (t <= len && height[t - 1] >= height[i - 1]) {
                    t = right[t];
                }
                right[i] = t;
            }
        }
        int ans = 0;
        for (int i = 1; i <= len; i++) {
            int t = right[i] - (left[i] + 1);
            ans = max(ans, t * height[i - 1]);
        }
        return ans;
    }
};
