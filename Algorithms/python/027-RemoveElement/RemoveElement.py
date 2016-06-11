class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        k = 0
        for item in nums:
            if item != val:
                nums[k] = item
                k += 1
        return k
