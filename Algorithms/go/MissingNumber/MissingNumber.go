// Source : https://leetcode.com/problems/missing-number/
// Author : Ke Li
// Date   : 2016-03-17

/***************************************************************************************
 *
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the
 * one that is missing from the array.
 *
 * For example,
 * Given nums = [0, 1, 3] return 2.
 *
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement it using
 * only constant extra space complexity?
 *
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating
 * all test cases.
 ***************************************************************************************/

 func missingNumber(nums []int) int {
     sum := 0
     for _, x := range nums {
         sum += x
     }
     n := len(nums)
     return n * (n + 1) / 2 - sum
 }
