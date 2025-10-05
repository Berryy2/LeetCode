/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) 
{
    int n = digitsSize - 1;
    int carry = 1;
    while(n >= 0)
    {
        if(digits[n] == 9)
        {
            digits[n] = 0;
        }
        else
        {
        digits[n]++;
        carry = 0;
        break;
        }
        n--;
    }
    if(carry == 0)
    {
        *returnSize = digitsSize;
        return digits;
    }
    int *res = (int*)malloc(sizeof(int) * (digitsSize + 1));
    res[0] = 1;
    for(int i = 0; i < digitsSize; i++)
    {
        res[i + 1] = digits[i];
    }
    *returnSize = digitsSize + 1;
    return res;
}