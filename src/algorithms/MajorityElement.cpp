class Solution {
public:
    int majorityElement(vector<int> &num) {
        int ret = 0, count = 0;
        map<int, int> map;
        int sizeOfNum = num.size();

        for (int i = 0; i < sizeOfNum; i++) {
        	map[num[i]]++;
        }
        for (int i = 0; i < sizeOfNum; i++) {
        	int tt = map[num[i]];
        	if (count < tt) {
        	    count = tt;
        	    ret = num[i];
        	}
        }
        return ret;
    }
};
