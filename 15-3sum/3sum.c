/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */

// Helper: BubbleSort to sort the input array in ascending order.
void BubbleSort(int* s, int size) 
{
    // Variable nesscary for swaping.
    int temp = 0;
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = 0; j < size - i - 1; j++) 
        {
            if (s[j] > s[j + 1]) {
                // Swap elements.
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) 
{
    // initially no triplets found.
    *returnSize = 0;  
    
    // Allocate array to hold column sizes.
    // Each row (triplet) will have exactly 3 integers.
    *returnColumnSizes = (int*)malloc(sizeof(int) * numsSize);  

    // Edge case: fewer than 3 numbers → no triplets
    if (numsSize < 3)
    {
        // return empty array of arrays (2D array);
        return (int**)malloc(0);  
    }

    // Initial memory capacity for storing triplets.
    // (we don’t know the exact number of triplets in advance,
    // so we start with a guess and grow with realloc if needed).
    int capacity = 1000;
    
    // Allocate memory for an array of int* (each int* will point to a triplet of 3 ints).
    int** result = (int**)malloc(sizeof(int*) * capacity);
    
    // Allocate memory for column sizes (parallel array to result[]).
    // For 3Sum, every row will always have 3 integers.
    *returnColumnSizes = (int*)malloc(sizeof(int) * capacity);

    // Sort nums to use two-pointer method.
    BubbleSort(nums, numsSize);

    // Iterate each element as the "first" element in the triplet.
    for (int i = 0; i < numsSize - 1; i++)
    {
        // Skip duplicates to avoid repeating the same triplet.
        if ((i > 0) && (nums[i] == nums[i - 1]))
            continue;
        // left pointer
        int L = i + 1;
        // right pointer           
        int R = numsSize - 1;    

        // Move L and R inward while searching for valid triplets
        while (L < R) 
        {
            int sum = nums[i] + nums[L] + nums[R];

            if (sum == 0) 
            {
                // ---- MEMORY ALLOCATION PART ----
                // Allocate memory for this triplet (3 integers)
                result[*returnSize] = (int*)malloc(sizeof(int) * 3);

                // Save the values into the allocated memory
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[L];
                result[*returnSize][2] = nums[R];

                // Mark the size of this row as 3
                (*returnColumnSizes)[*returnSize] = 3;

                // Increase the count of total triplets found
                (*returnSize)++;

                // Check Memory Capacity.
                // If we filled up all allocated slots, double the capacity
                if((*returnSize) >= capacity) 
                {
                    // If capacity is not enough we double it and reallocate in memory.
                    capacity *= 2;
                    result = (int**)realloc(result, sizeof(int*) * capacity);
                    *returnColumnSizes = (int*)realloc(*returnColumnSizes, sizeof(int) * capacity);
                }

                // Skip Duplicate index.
                while ((L < R) && (nums[L] == nums[L + 1]))
                    L++;
                while ((L < R) && (nums[R] == nums[R - 1]))
                    R--;

                // Move both pointers inward
                L++;
                R--;
            } 
            else if (sum < 0) 
            {
                // sum too small → increase by moving left pointer
                L++;  
            } 
            else 
            
                // sum too large → decrease by moving right pointer{
                R--;  
        
        }
    }
    // Return all triplets found
    return result;
}
