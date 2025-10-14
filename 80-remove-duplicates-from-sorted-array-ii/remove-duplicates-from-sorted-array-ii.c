int removeDuplicates(int* nums, int numsSize) 
{
    int F = 1;
    int R = 1;
    int counter = 1;
    while(F < numsSize)
    {
        if(nums[F] == nums[F - 1])
        {
            counter++;
        }
        else
        {
            counter = 1;
        }
        if(counter <= 2)
        {
            nums[R] = nums[F];
            R++;
        }
        F++;
    }    
    return R;
}