void reverse(int* arr,int start, int end)
{
    while(start < end)
    {
        int temp;
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rotate(int* nums, int numsSize, int k) 
{
    k %= numsSize;
    if(numsSize == 0)  return;
    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);
}