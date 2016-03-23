// Source : https://leetcode.com/problems/increasing-triplet-subsequence/
// Author : Ke Li
// Date   : 2016-03-23

/*************************************************************************************** 
 *
 * Given an unsorted array return whether an increasing subsequence of length 3 exists 
 * or not in the array.
 * 
 * Formally the function should:
 * Return true if there exists i, j, k  
 * such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 
 * else return false.
 * 
 * Your algorithm should run in O(n) time complexity and O(1) space complexity.
 * 
 * Examples:
 * Given [1, 2, 3, 4, 5],
 * return true.
 * 
 * Given [5, 4, 3, 2, 1],
 * return false.
 * 
 * Credits:Special thanks to @DjangoUnchained for adding this problem and creating all 
 * test cases.
 ***************************************************************************************/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return false;
        bool hasTop2 = false;
        bool hasMaxFromHead = false;
        int maxFromTail = nums[n - 1];
        int maxFromHead, top2;
        
        for (int i = n - 2; i >= 0; i--) {
            if (!hasTop2) {
                if (nums[i] > maxFromTail) {
                    maxFromTail = nums[i];
                } else if (nums[i] < maxFromTail) {
                    top2 = nums[i];
                    hasTop2 = true;
                }
            } else {
                if (nums[i] < top2) return true;
                if (!hasMaxFromHead) {
                    if (nums[i] > top2 && nums[i] < maxFromTail) {
                        top2 = nums[i];
                    } else if (nums[i] > maxFromTail) {
                        hasMaxFromHead = true;
                        maxFromHead = nums[i];
                    }
                } else {
                    if (nums[i] > maxFromHead) {
                        maxFromHead = nums[i];
                    }
                    else if (nums[i] > top2 && nums[i] < maxFromHead) {
                        maxFromTail = maxFromHead;
                        top2 = nums[i];
                        hasMaxFromHead = false;
                    }
                }
            }
        }
        
        return false;
    }
};