// Source : https://leetcode.com/problems/4sum/
// Author : Ke Li
// Date   : 2016-03-27

/*************************************************************************************** 
 *
 * Given an array S of n integers, are there elements a, b, c, and d in S such that a + 
 * b + c + d = target? Find all unique quadruplets in the array which gives the sum of 
 * target.
 * 
 * Note:
 * 
 * Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ 
 * d)
 * The solution set must not contain duplicate quadruplets.
 * 
 *     For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
 * 
 *     A solution set is:
 *     (-1,  0, 0, 1)
 *     (-2, -1, 1, 2)
 *     (-2,  0, 0, 2)
 ***************************************************************************************/

const int MAX_SIZE = 1000005;
struct Node {
    int v, x, y;
};

Node d[MAX_SIZE];

// custom Node Comparator
bool comparator(const Node& a, const Node& b) {
    if (a.v != b.v)
        return a.v < b.v;
    if (a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int pos = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                d[pos].v = nums[i] + nums[j];
                d[pos].x = i;
                d[pos++].y = j;
            }
        }
        
        // sort the combine sum array
        sort(d, d + pos, comparator);
        
        vector<vector<int> > matchlist;
        
        for (int i = 0; i < pos; i++) {
            int temp = target - d[i].v;
            int l = i + 1, r = pos - 1;
            
            while (l <= r) {
                int m = (l + r) / 2;
                if (d[m].v == temp) {
                    int j = m;
                    // get the index before first
                    while (j >= 0 && d[j].v == temp)j--;
                    
                    for (j++; j < pos; j++) {
                        if (d[j].v != temp) break;
                        if (d[j].x != d[i].x && d[j].x != d[i].y
                                && d[j].y != d[i].x && d[j].y != d[i].y) {
                            vector<int> item;
                            item.push_back(nums[d[i].x]);
                            item.push_back(nums[d[i].y]);
                            item.push_back(nums[d[j].x]);
                            item.push_back(nums[d[j].y]);
                            sort(item.begin(), item.end());
                            matchlist.push_back(item);
                        }
                    }
                    break;
                } else if (d[m].v > temp) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
        }
        // remove repeated items
        return distinct(matchlist);
    }
private:
    
    vector<vector<int> > distinct(vector<vector<int> > vecs) {
        vector<vector<int> > result;
        int sizeofvecs = vecs.size();
        
        for (int i = 0; i < sizeofans; i++) {
            bool has = false;
            for (int j = 0; j < result.size(); j++) {
                if (equal(vecs[i], result[j])) {
                    has = true;
                    break;
                }
            }
            if (!has) {
                result.push_back(vecs[i]);
            }
        }
        return result;
    }
    
    // check if two vectors are equal
    bool equal(vector<int>& a, vector<int>& b) {
        for (int i = 0; i < 4; i++) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }
};
