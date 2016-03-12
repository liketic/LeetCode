class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        steps = [0] * (n + 1)

        for i in range(n + 1):
            if i == 0:
                steps[i] = 1
                continue
            if i >= 1:
                steps[i] += steps[i - 1]
            if i >= 2:
                steps[i] += steps[i - 2]

        return steps[n]
