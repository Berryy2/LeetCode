class Solution(object):
    def smallestNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        res = 1
        while (res - 1) < n:
            res *= 2
        return res - 1
        