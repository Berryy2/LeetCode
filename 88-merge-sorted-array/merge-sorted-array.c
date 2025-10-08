// In this problem we will use ptr for each array starting from the 
// last valid element to be sorted.
// Then compare the value of the element in the 2 arrays
// and insert the larger one in the nums1 array from the end (m + n -1)
// Then decrement the ptr which was pointing to the larger element and the 
// same for the ptr pointing to the last place in the array where i will sort.
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) 
{
    // Pointer A starts at the end of the valid elements in nums1.
    int ptrA = m - 1;
    // Pointer B starts at the end of nums2.
    int ptrB = n - 1;
    // Result pointer starts at the very end of nums1 (where extra space is reserved)
    int ptrRes = m + n - 1;
    // We’ll merge the arrays starting from the back.
    // This avoids overwriting elements in nums1 that haven’t been compared yet.
    while(ptrB >= 0)
    {
        // If ptrA is still within range and nums1’s element is larger,
        // copy that element to the end of nums1 (current ptrRes position).
        if((ptrA >= 0) && nums1[ptrA] > nums2[ptrB])
        {
            // Move both pointers A and Res left (to the next element).
            nums1[ptrRes--] = nums1[ptrA--];
        }
        // Otherwise, take nums2’s current element (it’s larger or ptrA is exhausted)
        // and place it into nums1 at the current result position.
        // then move both pointers B and Res (to the next element).
        else
        nums1[ptrRes--] = nums2[ptrB--];
    }    
}