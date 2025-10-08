class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        candidate = 0
        vote = 0
        for num in nums:
            if vote == 0:
                candidate = num
                vote += 1
            else:
                if(num == candidate):
                    vote += 1
                else:
                    vote -= 1
        count = 0
        for num in nums:
            if num == candidate:
                count += 1
            if count > len(nums) / 2:
                return candidate
        return -1       