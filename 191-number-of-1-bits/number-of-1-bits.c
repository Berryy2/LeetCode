int hammingWeight(int n) 
{
    // Intialize counter by zero.
    int counter  = 0;

    // Looping in the 32 bits.
    for(int i = 0; i < 32; i++)
    {
        // If the bit is "1" increment counter.
        if(n & 1)
        {
            counter++;
        }

        // Shift (n) to the right.
        n >>= 1;
    }
     
    // At the end return counter.
    return counter;
}
