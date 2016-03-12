class Solution(object):
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        v = 0

        for c in s:
            v = v * 26 + (ord(c) - ord('A') + 1)

        return v
