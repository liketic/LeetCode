class Solution(object):
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        while num > 9:
            digits_sum = 0
            while num > 0:
                digits_sum += num % 10
                num /= 10
            num = digits_sum

        return num
