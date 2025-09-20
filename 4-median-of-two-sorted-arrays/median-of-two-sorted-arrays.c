#include <math.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
     if (nums1Size > nums2Size )
    {
        return findMedianSortedArrays(nums2 , nums2Size , nums1 , nums1Size);
    }
    int m = nums1Size , n = nums2Size;
    int Start = 0 , End = m;
    while (Start <= End )
    {
        int PartitionA = (Start + End) / 2;
        int PartitionB = (m + n + 1) / 2 - PartitionA;
        int maxLeftA  = (PartitionA == 0 ? -1 * INFINITY : nums1[PartitionA - 1]);
        int minRightA = (PartitionA == m ?  INFINITY : nums1[PartitionA]);
        int maxLeftB  = (PartitionB== 0) ? -1 * INFINITY : nums2[PartitionB - 1] ;
        int minRightB = (PartitionB == n ?  INFINITY : nums2[PartitionB]);
        
        if ((maxLeftA <= minRightB) && (maxLeftB <= minRightA))
        {
        if ((m + n) % 2 == 0 )
        {
        	return ((double)fmax(maxLeftA,maxLeftB) + (double)fmin(minRightA,minRightB)) / 2;
        }
        else
        {
        	return fmax(maxLeftA,maxLeftB);
        }
        }
        else if (maxLeftA > minRightB)
        {
        	End = PartitionA - 1;
        }
        else 
        {
        	Start = PartitionA + 1 ;
        }
    }
return 0.0;
}