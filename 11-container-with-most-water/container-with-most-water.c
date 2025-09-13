int maxArea(int* height, int heightSize) 
{
    int i = 0;
    int j = heightSize - 1;
    int max = 0;
    
    while(i != j)
    {
        int Area = fmin(height[j], height[i]) * (j - i);
        if (Area > max)
        {
            max = Area;
        }
       if (height[j] > height[i])
       {
        i++;
       }
       else
       {
        j--;
       }
    }
    return max;
}