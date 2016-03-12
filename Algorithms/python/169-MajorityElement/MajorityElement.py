class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums_count = dict()

        for v in nums:
            if v not in nums_count:
                c = 1
            else:
                c = nums_count[v] + 1

            if c > len(nums) / 2:
                return v
            nums_count[v] = c
