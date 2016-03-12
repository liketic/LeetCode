class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int n = num.size();
        // sort numbers first
        sort(num.begin(), num.end());

        vector< vector<int> > ans;

        for (int i = 0; i < n; i++) {
            if (i && num[i] == num[i - 1])
                continue;
            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && num[j] == num[j - 1])
                    continue;

                int t = (num[i] + num[j]) * - 1;

                // binary search the target number in the rest numbers
                int startIndex = j + 1, endIndex = n - 1;

                while (startIndex <= endIndex) {
                    int mid = (startIndex + endIndex) / 2;
                    if (num[mid] == t) {
                        vector<int> arr;
                        arr.push_back(num[i]);
                        arr.push_back(num[j]);
                        arr.push_back(num[mid]);
                        ans.push_back(arr);
                        break;
                    }
                    else if (num[mid] < t) {
                        startIndex = mid + 1;
                    }
                    else {
                        endIndex = mid - 1;
                    }
                }
            }
        }
        return ans;
    }
};
