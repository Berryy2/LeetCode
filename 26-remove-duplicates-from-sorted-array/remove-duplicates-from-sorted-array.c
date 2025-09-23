int removeDuplicates(int* nums, int numsSize) 
{
    int counter = 1;
    int L = 0;
    int R = 1;
    
        while ( R != numsSize)
        {
           if(nums[L] == nums[R])
           {
            R++;
           }
           else
           {
            nums[L+1] = nums[R];
            L++;
            counter++;
           }
        }
    return counter;
}
