/****************************************************************************************************
* In this problem we just need to know that the power of 2's minus 1 always equal a number which all
* its binary y representation contains only set bits (1).
* i.e. For any power of 2 (say 2^k), subtracting 1 gives a number whose binary representation 
* consists entirely of 1s. 
* Example: 
*   2^3 = 8 → 8 - 1 = 7 → (111 in binary)
* So, we will loop multiplying a variable by 2 (checking all the power of 2's) until reaching the 
* the smallest number that's greater than or equal to n.
*****************************************************************************************************/
int smallestNumber(int n) 
{
    // Set a variable = 1 (not zero as everything multiply by zero equals zero (its known i know xD))
    int result = 1;

    // Check the power of 2's and but a condition that the result variable is - 1 to avoid corner case
    // eg.: n = 1.
    while((result - 1) < n)
    {
        // Move to the next power of 2.
        result *= 2;
    }
    // Breaking the loop means we find the smallest power of greater than or equal to n.
    // and then subtracting 1 to get the number which all its  binary representation contains only set
    // bits.    
    return result - 1;
}