// Lets try Binary Search Algorithm on an easy problem
int searchInsert(int* nums, int numsSize, int target) 
{
    // We initialize our Left and Right pointers at the array's boundries.
    int L = 0;
    int R = numsSize - 1;

    // We iterate until L passed R -> that means the target is not in the array
    // but if it was there L will be pointed at it.
    while(L <= R)
    {
        // We make the formula of the mediam index.
        // Remember that we first subtract L from R and divide the result by 2
        // then add the L at the end. 
        // also this formula prevents overflow of the medium.
        int M = L + (R - L) / 2;
        // If the medium's value is more than the target.
        // we will search the first half by make the end boundry of the array = M - 1. 
        if(nums[M] > target)
        {
            R = M - 1;
        }
        // If the medium's value is less than the target.
        // we will search the second half by make the start boundry of the array = M + 1. 
        else if(nums[M] < target)
        {
            L = M + 1;
        }
        // If we reached here that means the medium's value is the target.
        // so, we return the index.
        else return M;
    }
    // If we break the while loop, like we said that means the target is not present
    // L will be the correct insertion index to keep the array sorted 
    return L;
}

// Problem can be solved easily by linear scan with a simple condition statments with
// a O(n)
// but the problem requires O(log(n)) time complexity.(which is better btw) 