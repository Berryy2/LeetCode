// We can take 2 approaches:
// 1. A simple but slower approach: keep subtracting divisor from dividend
//    until dividend < divisor. This has O(n) time complexity.
// 2. A more efficient approach: use bit shifting to subtract the largest
//    possible multiple of divisor each time. This reduces the time complexity
//    to O(log(dividend)).
int divide(int dividend, int divisor) 
{
    // First, determine the sign of the result.
    // XOR trick: if exactly one of dividend or divisor is negative,
    // then the result must be negative. negative = 1 -> result should be negative.
    //                                   negative = 0 -> result should be positive.   
    int negative = (dividend < 0) ^ (divisor < 0);
    // Work with positive values using absolute values.
    // Cast to long long to safely handle INT_MIN edge case.
    long long a = llabs((long long)dividend);
    long long b = llabs((long long)divisor);
    // Intialize the quotient to get the result at the end by adding quotient each loop.
    long long quotient  = 0;
    
    // While dividend is still greater than or equal to divisor,
    // we keep subtracting the largest possible multiple of divisor.
    while(a >= b)
    {
    // Intialize temp and multiple to use in the bit operator
    // as quotient will use the multiple variable to update its value.
    // and temp will get the largest power of the divisor to be subtracted from dividend.
    long long temp = b;
    long long multiple = 1;
    while((temp << 1) <= a)
    {
        temp = temp << 1;
        multiple = multiple << 1;
    }
    // Update the value of quotient and dividend.
    quotient += multiple;
    a -= temp;
    }
    // Then, we use the negative value we made at the begining.
    if (negative)
    quotient = -quotient;
    // then put the overflow conditions.
    if(quotient > INT_MAX) return INT_MAX;
    if(quotient < INT_MIN) return INT_MIN;
    // we return casted quotient to not get any decimal value.
    return (int)quotient;
}