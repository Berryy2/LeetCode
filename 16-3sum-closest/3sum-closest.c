// BubbleSort function: sorts an array in ascending order.
// To be able to use the one fixed looping pointer and two moving pointers.
void BubbleSort(int* arr, int size)
{
    int temp;
    // outer loop: repeat passes.
    for(int i = 0; i < size - 1; i++)
    {
        // inner loop: compare neighbors.
        for(int j = 0; j < size - i - 1; j++)
        {
            // if the right element is smaller.
            if(arr[j + 1] < arr[j])
            {
            // swap arr[j] and arr[j+1].
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
            }
        }
    }
}

// Main function to find the closest sum of 3 numbers to the target.
int threeSumClosest(int* nums, int numsSize, int target) 
{
    // Sort the array to use two-pointer approach.
    BubbleSort(nums, numsSize);
    // Variables used to get the closest sum.
    // 1) Smallest difference found so far
    int min = INT_MAX;
    // 2) Difference between current sum and target
    int ClosestSum = 0;
    // 3) Current sum of three numbers
    int sum = 0;
    // 4) The actual sum we will return
    int Ret_Sum = 0;

    // Fix one number, loop with it and use two pointers for the other two.
    // loop until the 3rd last element as if used (numsSize - 1), at i = numsSize - 1,
    // L = i + 1 = numsSize (out of boundry), although the while condition will skip it.
    // but lets keep it safe.
    for(int i = 0; i < numsSize - 2; i++)
    {
        // Left pointer.
        int L = i + 1;
        // Right pointer.
        int R = numsSize - 1;
        // Move pointers inward while checking sums
        while(L < R)
        {
            // Calculate sum of triplet.
            sum = nums[i] + nums[L] + nums[R];
            // Distance from target.
            ClosestSum = abs(target - sum);
            // Update best result if closer than before.
            if(ClosestSum < min)
            {
                min = ClosestSum;
                Ret_Sum = sum;
            }
            // Move pointers based on comparison with target
            if(sum < target)
            {
                // Sum too small → increase by moving left pointer
                L++;
            }
            else if(sum > target)
            {
                // Sum too large → decrease by moving right pointer
                R--;
            }
            // Exact match → return immediately
            else return sum;
        }
    }
    // Return the closest sum found
    return Ret_Sum;
}