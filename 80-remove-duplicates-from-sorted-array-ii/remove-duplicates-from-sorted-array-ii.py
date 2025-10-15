class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        Front = 1
        Rear = 1
        count = 1

        while Front < len(nums):
            if nums[Front] == nums[Front - 1]:
                count += 1
            else:
                count = 1

            if count <= 2:
                nums[Rear] = nums[Front]
                Rear +=1
            Front += 1
        return Rear
        