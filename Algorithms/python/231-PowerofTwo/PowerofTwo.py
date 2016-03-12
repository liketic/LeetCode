class Solution(object):
    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """

        # as we say, we can clear last '1' digit like this
        # n &= n - 1, so the answer is
        return n > 0 and n & (n - 1) == 0
