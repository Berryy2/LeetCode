/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) 
{
    int *result = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    
    int L = 0;
    int R = numbersSize - 1;
    while(L < R)
    {
        int sum = numbers[L] + numbers[R];

        if(sum < target)
        {
            L++;
        }
        else if(sum > target)
        {
            R--;
        }
        else
        {
            result[0] = L + 1;
            result[1] = R + 1;
            return result;
        }
    }
    return false;
}