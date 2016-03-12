class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """

        if len(digits) == 0:
            return digits

        s = len(digits) - 1
        digits[s] += 1
        t = 0

        for i in range(s, -1, -1):
            digits[i] += t
            t = digits[i] / 10
            if digits[i] < 10:
                break
            digits[i] -= 10
        if t > 0:
            return [t] + digits[:]
        return digits
