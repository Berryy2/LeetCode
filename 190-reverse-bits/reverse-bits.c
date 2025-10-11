/********************************************************************************************************
* This is a bit manipulation problem where we reverse the bits of a 32-bit unsigned integer.
* We iterate 32 times (once for each bit), shifting bits from 'n' into 'rev' in reverse order.
* In each iteration, we:
*   1. Shift 'rev' left to make space for the next bit.
*   2. Copy the least significant bit of 'n' into 'rev' (if it’s 1).
*   3. Shift 'n' right to process the next bit.  
*********************************************************************************************************/
int reverseBits(int n) 
{
    // Initiate rev to zero.
    int rev = 0;
    // Loop through the number of bits of the give input.
    for(int i = 0; i < 32; i++)
    {
        // We leave space for the next bit to be inserted.
        // ex: iteration 1
        //     rev = 0000
        //     n   = 1011
        //     iteration 2
        //     rev = 0001
        //     n   = 0101
        // then we leave space for rev making it: 0010 -> to insert the reversed bit without affecting
        // previous ones.
        rev <<= 1;
        // If the bit in n = 1 we insert it in rev by OR operator.
        if(n & 1)
        {
        rev |= 1;
        }
        // We shift n to the right to see the next most siginificant bit and so on..
        n >>= 1;
 }   
    // At the end returned the reversed bit number.
    return rev;
}
