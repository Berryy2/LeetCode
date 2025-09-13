// In this problem we will use the 2 pointers approach.
// You can save space just by making the 2 pointers i intialized as real 2 pointer (*i) & (*j).
int maxArea(int* height, int heightSize) 
{
    // Initialize two pointers at the extreme ends of the array
    
    // Left Pointer.
    int i = 0;
    //Right Pointer.
    int j = heightSize - 1;
    // Variable to store the maximum area found so far
    int max = 0;
    // Loop until the two pointers meet.
    // You can also loop while (j > i).
    while(i != j)
    {
        // Calculate the current area:
        // height is limited by the shorter of the two lines.
        // width is the distance between the two pointers.
        int Area = fmin(height[j], height[i]) * (j - i);
        // Update max if the current area is larger
        if (Area > max)
        {
            max = Area;
        }
       // Move the pointer pointing to the shorter line inward:
       // - Because the shorter line is the limiting factor
       // - Moving the taller line won’t help increase the area
       if (height[j] > height[i])
       {
        // Move left pointer to the right.
        i++;
       }
       else
       {
        // Move right pointer to the left.
        j--;
       }
    }
    // Return the maximum area found.
    return max;
}