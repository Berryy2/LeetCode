/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) 
{
    int* res = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    res[0] = -1;
    res[1] = -1;
    if(numsSize == 0) return res;
    int L = 0;
    int R = numsSize - 1;
    while(L < R)
    {
        int M = L + (R - L) / 2;
        if(nums[M] >= target)
        {
            R = M;
        }
        else L = M + 1;
    }
    if(nums[L] != target) return res;
    int F_pos = L;
    L = 0;
    R = numsSize - 1;
    while(L < R)
    {
        int M = L + (R - L) / 2 + 1;
        if(nums[M] <= target)
        {
            L = M;
        }
        else R = M - 1;
    }
    int L_pos = L;
    res[0] = F_pos;
    res[1] = L_pos;
    return res;

}