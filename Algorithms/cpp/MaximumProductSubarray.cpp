#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

class Solution {
public:
    int maxProduct(int A[], int n) {

        int prevMax = A[0]; // max value
        int prevMin = A[0]; // min value
        int ans = A[0];     // return value

        for (int i = 1; i < n; i++) {
            int tempMax = max(A[i], max(A[i] * prevMax, A[i] * prevMin));
            int tempMin = min(A[i], min(A[i] * prevMax, A[i] * prevMin));
            ans = max(ans, tempMax);
            prevMax = tempMax;
            prevMin = tempMin;
        }
        return ans;
    }
};
