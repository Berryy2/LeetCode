int majorityElement(int* nums, int numsSize) 
{
    int candidate = 0;
    int vote = 0;
    for(int i = 0; i < numsSize; i++)
    {
        if(vote == 0)
        {
            candidate = nums[i];
            vote++;
        }
        else
        {
            if(nums[i] == candidate)
                vote++;
            else 
                vote--;
        }
    }
        int count = 0;
        for(int i = 0; i < numsSize; i++)
        {
            if(nums[i] == candidate)
            count++;
        }
        if(count > (numsSize / 2))
        return candidate;
        return -1;
}