/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for(int i = 0 ; i< numsSize; i++ )
    {
        for(int j = 1 ; j< numsSize ; j++ )
        {
            if ((i != j) && (nums[i] + nums[j] == target))
            {
                int* result = (int*)malloc(2 * sizeof(int)); 
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}