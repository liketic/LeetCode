class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int sizeOfNum = num.size();

        for (int i = 0; i < sizeOfNum; i++) {
            if ((i == 0 || num[i] > num[i - 1])
                    && (i == sizeOfNum - 1 || num[i] > num[i + 1])) {
                return i;
            }
        }
        return -1; // unreachable
    }
};
