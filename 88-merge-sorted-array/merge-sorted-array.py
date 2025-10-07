'''
In this problem we will use ptr for each array starting from the last valid element
to be sorted.
then compare the value of the element in the 2 arrays and insert the larger one 
in the nums1 array from the end (m + n -1) then decrement the ptr which was pointing
to the larger element and the same for the ptr pointing to the last place in the
array where i will sort.  
'''
class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: None Do not return anything, modify nums1 in-place instead.
        """
        # Pointer A starts at the end of the valid elements in nums1.
        ptrA = m - 1
        # Pointer B starts at the end of nums2.
        ptrB = n - 1
        # Result pointer starts at the very end of nums1 (where extra space is reserved).
        ptrRes = m + n - 1
        # We’ll merge the arrays starting from the back.
        # This avoids overwriting elements in nums1 that haven’t been compared yet.
        while(ptrB >= 0):
            # If ptrA is still within range and nums1’s element is larger,
            # copy that element to the end of nums1 (current ptrRes position).
            if (ptrA >= 0)  and (nums1[ptrA] >= nums2[ptrB]):
                nums1[ptrRes] = nums1[ptrA]
                # Move pointer A left (to the next largest remaining element).
                ptrA -=1
            # Otherwise, take nums2’s current element (it’s larger or ptrA is exhausted)
            # and place it into nums1 at the current result position.
            else:
                nums1[ptrRes] = nums2[ptrB] 
                # Move pointer B left.
                ptrB -= 1
            # Move the result pointer left to fill the next position.
            ptrRes -=1