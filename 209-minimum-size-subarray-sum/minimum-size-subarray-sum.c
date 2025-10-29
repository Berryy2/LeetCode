int minSubArrayLen(int target, int* nums, int numsSize) 
{
    int L = 0;
    int R = 0;
    int sum = 0;
    int minLen = INT_MAX;
    while(R < numsSize)
    {
        sum += nums[R];
        while(sum >= target)
        {
            if(minLen > R - L + 1)
            {
                minLen = R - L + 1;
            }
            sum -= nums[L++];
        }
        R++;
    }
    return (minLen == INT_MAX) ? 0 : minLen;
}