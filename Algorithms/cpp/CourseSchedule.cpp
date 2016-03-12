class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        int n = prerequisites.size();
        int* out = new int[numCourses];
        memset(out, 0, sizeof(int) * numCourses);

        vector<int> vet[numCourses];

        for (int i = 0; i < n; i++) {
            int a = prerequisites[i].first;
            int b = prerequisites[i].second;
            vet[b].push_back(a);
            out[a]++;
        }
        queue<int> outIsZero;
        for (int i = 0; i < numCourses; i++) {
            if (!out[i]) {
                outIsZero.push(i);
            }
        }
        int total = 0;
        while (!outIsZero.empty()) {
            int t = outIsZero.front();
            outIsZero.pop();
            int v;
            for (int i = 0; i < vet[t].size(); i++) {
                v = vet[t][i];
                out[v]--;
                if (out[v] == 0) {
                    outIsZero.push(v);
                }
            }
            total++;
        }
        delete out;
        out = NULL;
        return (total == numCourses);
    }
};
