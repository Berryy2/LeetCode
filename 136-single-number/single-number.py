class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        StartNum = 0
        for num in nums:
            StartNum ^= num
        return StartNum 