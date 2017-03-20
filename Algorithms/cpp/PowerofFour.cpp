// Source : https://leetcode.com/problems/power-of-four
// Author : Ke Li
// Date   : 2017-03-20

/*************************************************************************************** 
 *
 * Given an integer (signed 32 bits), write a function to check whether it is a power 
 * of 4.
 * 
 * Example:
 * Given num = 16, return true.
 * Given num = 5, return false.
 * 
 * Follow up: Could you solve it without loops/recursion?
 * 
 * Credits:Special thanks to @yukuairoy  for adding this problem and creating all test 
 * cases.
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
 *             Bit Manipulation
 *             
 *           
 *         
 *       
 * 
 *       
 *         
 *           Show Similar Problems
 *           
 *             
 *             
 ***************************************************************************************/

class Solution {
public:
    bool isPowerOfFour(int num) {
        int count = 0;
        while (num > 1) {
            if (!(num & 1)) {
                count++;
                num /= 2;
            }
            else {
                break;
            }
        }
        return num == 1 && count % 2 == 0;
    }
};
