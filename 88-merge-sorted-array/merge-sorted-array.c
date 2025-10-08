void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) 
{
    int ptrA = m - 1;
    int ptrB = n - 1;
    int ptrRes = m + n - 1;
    while(ptrB >= 0)
    {
        if((ptrA >= 0) && nums1[ptrA] > nums2[ptrB])
        {
            nums1[ptrRes--] = nums1[ptrA--];
        }
        else
        nums1[ptrRes--] = nums2[ptrB--];
    }    
}