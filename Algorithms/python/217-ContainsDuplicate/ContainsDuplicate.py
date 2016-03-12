class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        nums_count = dict()

        for v in nums:
            if v not in nums_count:
                nums_count[v] = 1
                continue
            c = nums_count[v]
            if c > 0:
                return True
            nums_count[v] = c + 1

        return False
