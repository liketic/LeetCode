class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        chars_count = dict()

        for c in s:
            if c not in chars_count:
                chars_count[c] = 1
            else:
                chars_count[c] += 1

        for c in t:
            if c not in chars_count:
                return False
            chars_count[c] -= 1

        for k in chars_count.keys():
            if chars_count[k] != 0:
                return False
        return True
