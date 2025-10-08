int removeElement(int* nums, int numsSize, int val) 
{
    int L = 0;
    int R = numsSize - 1;
    int k = 0;
    while(L <= R)
    {
        int temp;
        if(nums[L] == val)
        {
            temp = nums[L];
            nums[L] = nums[R];
            nums[R] = temp;
            R--;
        }
        else
            L++; 
    }
    return L;
}