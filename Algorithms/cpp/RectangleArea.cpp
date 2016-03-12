class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long long int s = 0;
        s += (long long int)(C - A) * (D - B);
        s += (long long int)(G - E) * (H - F);

        s -= (max((long long int)min(D, H) - max(B, F), 0LL)) * max((long long int)min(C, G) - max(A, E), 0LL);
        return s;
    }
};
