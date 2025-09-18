/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// Bubble sort like we did in the previous problems.
//  
void BubbleSort(int* arr, int n)
{
     // Variable nesscary for swaping.
    int temp = 0;
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            // Swap elements until they are in order.
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) 
{
    *returnSize = 0;
    // no quadruplets possible.
    if (numsSize < 4) return NULL;  
    // Sort the input's array.
    BubbleSort(nums, numsSize);
   
    //  Allocate memory for result storage.
    // capacity = 1000 is an intila guess if its not enough we will reallocate in a bigger capacity later.
    int capacity = 1000;
    int** result = (int**)malloc(sizeof(int*) * capacity);
    *returnColumnSizes = (int*)malloc(sizeof(int) * capacity);

    // Loop through with 2 fixed pointers (i, j) and 2 moving pointers (L, R).
    for(int i = 0; i < numsSize - 2; i++)
    {
        // skip duplicates for i
        if (i > 0 && nums[i] == nums[i-1]) continue; 

        for(int j = i + 1; j < numsSize - 2; j++)
        {
        // skip duplicates for j
        if ((j > i + 1) && (nums[j] == nums[j-1])) continue;  
            int L = j + 1;
            int R = numsSize - 1;
            while(L < R)
            {
                long long sum = (long long)nums[i] + nums[j] + nums[L] + nums[R];
                if(sum == target)
                {
                    // Save quadruplet into result.
                    result[*returnSize] = (int*)malloc(sizeof(int) * 4);
                    result[*returnSize][0] = nums[i];
                    result[*returnSize][1] = nums[j];
                    result[*returnSize][2] = nums[L];
                    result[*returnSize][3] = nums[R];
                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;

                    // Resize if capacity exceeded.
                    if(*returnSize >= capacity)
                    {
                        capacity *= 2;
                        result = (int**)realloc(result, sizeof(int*) * capacity);
                        *returnColumnSizes = (int*)realloc(*returnColumnSizes, sizeof(int) * capacity);
                    }
                    // Skip duplicates for L.
                    while((L < R) && (nums[L] == nums[L + 1])) L++;
                    // Skip duplicates for R.
                    while((L < R) && (nums[R] == nums[R - 1])) R--;
                    // At the end move L and R till they meet.
                    L++;
                    R--;
                }
                // This means we need to increase the value of the number
                // and the array is sorted so we go to the next element from the left
                // as it will have a greater value.
                else if(sum < target)
                {
                    L++;
                }
                else
                // This means we need to decrease the value of the number
                // and the array is sorted so we go to the previous element from the right
                // as it will have a smaller value.
                {
                    R--;
                }
            }
        }
    }
    // At the end return the result.
    return result;
}