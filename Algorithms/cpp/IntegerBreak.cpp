// Source : https://leetcode.com/problems/integer-break
// Author : Ke Li
// Date   : 2017-03-20

/*************************************************************************************** 
 *
 * Given a positive integer n, break it into the sum of at least two positive integers 
 * and maximize the product of those integers. Return the maximum product you can get.
 * 
 * For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 
 * + 4).
 * 
 * Note: You may assume that n is not less than 2 and not larger than 58.
 * 
 *   There is a simple O(n) solution to this problem.
 *   You may check the breaking results of n ranging from 7 to 10 to discover the 
 * regularities.
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating 
 * all test cases.
 *       
 *         
 *           Subscribe to see which companies asked this question.
 *         
 *       
 * 
 *       
 *         
 *           Show Tags
 *           
 *             
 *             Dynamic Programming
 *             
 *             Math
 ***************************************************************************************/

class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) {
            return n - 1;
        }
        long long x = 0;
        for (int i = 2; i <= n; i++) {
            x = max(x, dfs(n - i, i, i));
        }
        return x;
    }
    
    long long dfs(int n, long long prod, int last) {
        if (n == 0) {
            return prod;
        }
        if (n < last) {
            return prod * n;
        }
        long long r = 0;
        for (int i = last; i <= n; i++) {
            r = max(r, dfs(n - i, prod * i, i));
        }
        return r;
    }
};
