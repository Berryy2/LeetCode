// Lets try Binary Search Algorithm on an easy problem
int searchInsert(int* nums, int numsSize, int target) 
{
    int L = 0;
    int R = numsSize - 1;

    while(L <= R)
    {
        int M = L + (R - L) / 2;
        if(nums[M] > target)
        {
            R = M - 1;
        }
        else if(nums[M] < target)
        {
            L = M + 1;
        }
        else return M;
    }
    return L;
}