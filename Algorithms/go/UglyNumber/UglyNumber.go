// Source : https://leetcode.com/problems/ugly-number/
// Author : Ke Li
// Date   : 2016-03-17

/***************************************************************************************
 *
 * Write a program to check whether a given number is an ugly number.
 *
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For
 * example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
 *
 * Note that 1 is typically treated as an ugly number.
 *
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating
 * all test cases.
 ***************************************************************************************/

 func isUgly(num int) bool {
     if num <= 1 {
         return num == 1
     }
     for num % 2 == 0 {
         num /= 2
     }
     for num % 3 == 0 {
         num /= 3
     }
     for num % 5 == 0 {
         num /= 5
     }
     return num == 1
 }
