class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> ed[numCourses];
        int deg[numCourses];
        memset(deg, 0, sizeof(deg));

        for (int i = 0; i < prerequisites.size(); i++) {
            int a = prerequisites[i].first;
            int b = prerequisites[i].second;
            ed[b].push_back(a);
            deg[a]++;
        }
        vector<int> ans;

        int t = 0;
        while (t < numCourses) {
            bool has = false;
            for (int j = 0; j < numCourses; j++) {
                if (deg[j] == 0) {
                    deg[j] = -1;
                    ans.push_back(j);
                    for (int i = 0; i < ed[j].size(); i++) {
                        int tt = ed[j][i];
                        deg[tt]--;
                    }
                    t++;
                    has = true;
                }
            }
            if (t < numCourses && !has) {
                vector<int> v;
                return v;
            }
        }
        return ans;
    }
};
