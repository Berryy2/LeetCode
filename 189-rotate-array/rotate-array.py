class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        k %= n  # handle cases where k > n
        # nums[-k:] -> takes the last (k) elements of the array.
        # nums[:-k] -> take the elements of the array except the last k.
        # adding them together give us our rotated array by k.
        nums[:] = nums[-k:] + nums[:-k]  # rotate using slicing.