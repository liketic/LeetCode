class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        seen_num = dict()

        while n != 1:
            if n in seen_num:
                return False
            seen_num[n] = True
            n = Solution.count_digits_square(n)

        return True

    @staticmethod
    def count_digits_square(n):
        """
        :param n: number to cal
        :return: digits square sum
        """
        digit_square_sum = 0
        while n > 0:
            t = n % 10
            digit_square_sum += t * t
            n /= 10
        return digit_square_sum
