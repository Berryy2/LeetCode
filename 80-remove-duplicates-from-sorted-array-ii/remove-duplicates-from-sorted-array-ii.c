/********************************************************************************************************
* In this problem, we are given a sorted array and must remove extra duplicates in-place
* so that each unique element appears at most twice.
* We will go with two pointers approach:
*   - F (Front pointer): iterates through the array checking for duplicates.
*   - R (Rear pointer): marks the position where the next valid element should be placed.
*   - counter to track how many times the current element has appeared so far.
*********************************************************************************************************/
int removeDuplicates(int* nums, int numsSize) 
{
    // Corner case: If array size is less than or equal to 2, all elements are valid.
    if (numsSize <= 2) return numsSize;

    // Initialize pointers:
    // Front pointer to iterate through the array.
    int F = 1;
    // Rear pointer to mark next valid position.
    int R = 1;
    // Counts occurrences of the current number.
    int counter = 1;

    // Iterate through the array starting from the second element.
    while(F < numsSize)
    {
        // If current number equals previous, increment counter.
        if(nums[F] == nums[F - 1])
        {
            counter++;
        }
        // Otherwise, reset counter to 1 for the new number.
        else
        {
            counter = 1;
        }

        // If current number appeared at most twice,
        // we (keep) it by moving it to the result pointer position.
        if(counter <= 2)
        {
            nums[R] = nums[F];
            // Then Increments the Rear pointer.
            R++;
        }
         // Move the Front pointer to continue checking next elements.
        F++;
    }    
    // The array is now modified in-place; return new valid length.
    // by Rear pointer who only keep elements that apeeared at most twice. 
    return R;
}