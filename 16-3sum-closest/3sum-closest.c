void BubbleSort(int* arr, int size)
{
    int temp;
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            if(arr[j + 1] < arr[j])
            {
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
            }
        }
    }
}

int threeSumClosest(int* nums, int numsSize, int target) 
{
    BubbleSort(nums, numsSize);
    int min = INT_MAX;
    int ClosestSum = 0;
    int sum = 0;
    int Ret_Sum = 0;
    for(int i = 0; i < numsSize - 2; i++)
    {
        int L = i + 1;
        int R = numsSize - 1;
        while(L < R)
        {
            sum = nums[i] + nums[L] + nums[R];
            ClosestSum = abs(target - sum);
            if(ClosestSum < min)
            {
                min = ClosestSum;
                Ret_Sum = sum;
            }
            if(sum < target)
            {
                L++;
            }
            else if(sum > target)
            {
                R--;
            }
            else return sum;
        }
    }
    return Ret_Sum;
}