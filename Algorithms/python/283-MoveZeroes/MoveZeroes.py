class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """

        i = 0

        for j in range(len(nums)):
            if nums[j] == 0:
                i = max(i, j + 1)
                while i < len(nums):
                    if nums[i] != 0:
                        nums[i], nums[j] = nums[j], nums[i]
                        i += 1
                        break
                    i += 1
