class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        if len(nums) == 0:
            return 0
        d = list()
        d.append(nums[0])
        ans = nums[0]

        for i in range(1, len(nums)):
            t = 0
            for j in range(0, i - 1):
                t = max(t, d[j])
            a = t + nums[i]
            ans = max(ans, a)
            d.append(a)

        return ans
