class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        k = -1
        for i in range(len(nums)):
            if nums[i] != val:
                k += 1
                nums[k] = nums[i]
        return k + 1
