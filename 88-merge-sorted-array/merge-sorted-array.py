class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: None Do not return anything, modify nums1 in-place instead.
        """
        ptrA = m - 1
        ptrB = n - 1
        ptrRes = m + n - 1
        while(ptrB >= 0):
            if (ptrA >= 0)  and (nums1[ptrA] >= nums2[ptrB]):
                nums1[ptrRes] = nums1[ptrA]
                ptrA -=1
            else:
                nums1[ptrRes] = nums2[ptrB] 
                ptrB -= 1
            ptrRes -=1