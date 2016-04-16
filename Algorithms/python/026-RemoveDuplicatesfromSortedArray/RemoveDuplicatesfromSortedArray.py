class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        i = 0
        for item in nums:
            if item != nums[i]:
                i += 1
                nums[i] = item
        return i + 1
