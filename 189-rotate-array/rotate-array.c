/*****************************************************************************************************
 * In this approach we will rotate the array to the right by `k` steps using the "reverse" method.
 *      Idea:
 *      To rotate the array by `k` steps to the right:
 *      1. Reverse the entire array.
 *      2. Reverse the first `k` elements.
 *      3. Reverse the remaining `n - k` elements.
 *
 *      Ex:
 *      nums = [1,2,3,4,5,6,7], k = 3
 *      Step 1 → reverse all:      [7,6,5,4,3,2,1]
 *      Step 2 → reverse first k:  [5,6,7,4,3,2,1]
 *      Step 3 → reverse rest:     [5,6,7,1,2,3,4] 
  This is an optimal solution with: Time Complexity: O(n) (beats 100% ;)) - Space Complexity: O(1) 
 *****************************************************************************************************/
// We will use helper function to reverse a subarray between indices [start, end]
void reverse(int* arr,int start, int end)
{
    while(start < end)
    {
        // Swap elements at the start and end positions until the start and end meet.
        int temp;
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        // Shrink the start and end.
        start++;
        end--;
    }
}

void rotate(int* nums, int numsSize, int k) 
{
    // To avoid any unnecessary rotations when k > numsSize. 
    // -> used it in finding target of sorted but rotated array problem. 
    k %= numsSize;
    // Handle edge case — empty array.
    if(numsSize == 0)  return;
    // 1 ->  Reverse the entire array
    reverse(nums, 0, numsSize - 1);
    // 2 -> Reverse the first k elements
    reverse(nums, 0, k - 1);
    // 3 -> reverse the rest of the elements.
    reverse(nums, k, numsSize - 1);
}