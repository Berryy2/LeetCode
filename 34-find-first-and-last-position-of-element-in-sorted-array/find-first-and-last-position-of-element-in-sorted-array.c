/*************************************************************************
 * Note: The returned array must be malloced, assume caller calls free().
 ************************************************************************/
 // We will do a double binary search approach one to get the first position
 // of the target and one to get the last position of the target. 
 // 2 binary searches algorithms means O(2log(n)) = O(log(n))
int* searchRange(int* nums, int numsSize, int target, int* returnSize) 
{
    // Allocate memory for the result [firstPos, lastPos].
    int* res = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    // Initialize as -1 (default: not found).
    res[0] = -1;
    res[1] = -1;
    // Edge case: if array is empty, return [-1, -1].
    if(numsSize == 0) return res;
    // Set boundries for first Binary Search → Find First Occurrence.
    int L = 0;
    int R = numsSize - 1;
     // Standard binary search but biased towards the LEFT boundary.
    while(L < R)
    {
        // Normal mid (left bias).
        int M = L + (R - L) / 2;
        // If nums[M] >= target, move search window to the LEFT half.
        // (Because target could still be at M or earlier).
        if(nums[M] >= target)
        {
            R = M;
        }
        // Otherwise, nums[M] < target → discard left half.
        else L = M + 1;
    }
    // After the loop, L == R and points to the first position where target 
    // could be.
    // Target not found at all → return [-1,-1].
    if(nums[L] != target) return res;
    // Store the first position of target.
    int F_pos = L;
    // Reset boundries for the Second Binary Search → Find Last Occurrence.
    L = 0;
    R = numsSize - 1;
    // Standard binary search but biased towards the RIGHT boundary.
    while(L < R)
    {
        // Notice: bias mid to the RIGHT by adding +1
        // so that the loop converges to the last occurrence.
        int M = L + (R - L) / 2 + 1;
        // If nums[M] <= target, move search window to the RIGHT half.
        // (Because target could still be at M or later).
        if(nums[M] <= target)
        {
            L = M;
        }
        // Otherwise, nums[M] > target → discard right half.
        else R = M - 1;
    }
    // Store the last position of target.
    int L_pos = L;
    // Finally, Save and Return,
    res[0] = F_pos;
    res[1] = L_pos;
    return res;
}