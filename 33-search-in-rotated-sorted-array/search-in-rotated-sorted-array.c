// Here we will use double Binary search approach.
// First, binary search to reach the pivot point where the array is rotated.
// second one to search for the target. to get O(2log(n)) = O(log(n)).
int search(int* nums, int numsSize, int target) 
{
    // Step 1: Find the pivot (the index of the smallest element).
    // Initialize Left and Right pointers.
    int L = 0;
    int R = numsSize - 1;
    // This loop finds the smallest element (rotation pivot).
    // We shrink the search space until L == R.
    while(L < R)
    {
        // Remember that L and R are indecies not the value at the indices.
        int M = L + (R - L) / 2;
        // If mid value is greater than rightmost value,
        // that means the smallest element (pivot) is on the right side.
        if(nums[M] > nums[R])
        {
            L = M + 1;
        }
        // Otherwise, pivot is on the left side (including M itself).
        else R = M;
    }
    // At the end, L == R and both point to the pivot index.
    int pivot = L;
    // Step 2: Do a normal binary search, but adjust indices with pivot.
    // Reset!! search space back to whole array.
    L = 0;
    R = numsSize - 1;
    while(L <= R)
    {
        int M = L + (R - L) / 2;
        // "realMid" is the actual index in the rotated array.
        // It maps virtual index M (unrotated array) to the rotated array.
        int realMid = (M + pivot) % numsSize;
        // If the element at realMid is smaller than target,
        // we move L to search in the right half.
        if(nums[realMid] < target)
        {
            L = M + 1;
        }
        // If the element at realMid is greater than target,
        // we move R to search in the left half.
        else if(nums[realMid] > target)
        {
            R = M - 1;
        }
        // If nums[realMid] equals target, we found it → return its index.
        else return realMid;
    }
    // If we exit the loop, the target is not found in the array.
    return -1;
}