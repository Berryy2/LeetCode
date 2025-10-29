/********************************************************************************************************
* That a Sliding window problem in which we will expand the window by right point and add the sum of the
* elements while wxpanding until i reach or exceed the target, when that happens we will shring the window
* until we are less than the target and then expand and add again.
*- when we are equal to the target we then calaculate the length of the window (subarray) by 
*  (R - L + 1) and when we get a window less in length and equal to the target we update our
*  MinLen variable (which will be our output) to its length and continue til the right pointer reaches
*  the end of the array.
*  If the window approach end without updating the length of minLen (we never reached the exact target
*  value) -> we return zero at the end
********************************************************************************************************/
int minSubArrayLen(int target, int* nums, int numsSize) 
{
    // Left pointer of the sliding window for shrinking.
    int L = 0;  
    // Right pointer of the sliding window for expanding.            
    int R = 0;    
    // Current sum of the window for tracking the sum of the elements in the window.          
    int sum = 0;    
    // Smallest length found so far (We intialzie it with INT_MAX).        
    int minLen = INT_MAX;   

    // Expand the window by moving R across the array
    while (R < numsSize)
    {
        // Add the current number to the window sum.
        sum += nums[R];     

        // While the current window sum is greater than or equal to target
        while (sum >= target)
        {
            // Update minimum length if this window is smaller
            if (minLen > R - L + 1)
            {
                minLen = R - L + 1;
            }

            // Shrink the window from the left side to try and find a smaller valid window
            sum -= nums[L];
            // Move left pointer forward.
            L++;            
        }
        // Move right pointer forward to include next element.
        R++;                
    }

    // If minLen was never updated, that means no valid subarray was found
    // Otherwise, return the minimum length found
    return (minLen == INT_MAX) ? 0 : minLen;
}