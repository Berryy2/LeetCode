int removeDuplicates(int* nums, int numsSize) 
{
    // Counter keeps track of the number of unique elements in the array.
    // Since the first element is always unique, we start at 1.
    int counter = 1;

    // Left pointer (L) will mark the position of the last unique element found.
    int L = 0;

    // Right pointer (R) will scan through the array to find new unique elements.
    int R = 1;
    
    // Traverse the array until the right pointer reaches the end.
    while (R != numsSize)
    {
        // If nums[R] is equal to nums[L], it means it's a duplicate.
        if(nums[L] == nums[R])
        {
            // Just move R forward to keep searching for a new unique element.
            R++;
        }
        else
        {
            // Found a new unique element at nums[R].
            // Place it right after the last unique element (at L+1).
            nums[L+1] = nums[R];

            // Move L to this new unique element's position.
            L++;

            // Increase counter since we found a new unique element.
            counter++;

            // Then continue scanning with R.
            R++;
        }
    }

    // At the end, counter will hold the number of unique elements.
    // The first 'counter' elements of nums[] now contain those unique values.
    return counter;
}
