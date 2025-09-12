// In this code you will see 2 ways to deal with the overflow and underflow conditions.
// Just getting my hands used to preprocessing macros
// That is Preprocessor macros for integer limits (32-bit signed).
#define INT_MIN -2147483648 //2^31 -1 Max Limit.
#define INT_MAX  2147483647 //-2^31 Min Limit.
// Type of Parsing.
int myAtoi(char* s) {
    // Getting string length in a variable.
    int len = strlen(s);
    // Intialize i as Pointer to traverse the string.
    // Intialize sign to be used for Tracking the integer's sign (+1 or -1).
    int i = 0 , sign = 1;
    // intialize res to return it as the result -> Result accumulator.. 
    int res = 0;
    // Skipping Leading Whitespace.
    while (s[i] == ' ')
    {
        i++;
    }
    // Dealing with Signs using (sign) variable (Handle optional '+' or '-' sign.).
    if((s[i] == '+') || (s[i])== '-')
    {
        if(s[i] == '-')
        {
            // Apply negative sign if needed.
            sign = -1; 
        }
        // Move past the sign character..
        i++;
    }
    // Dealing with the digits in the string by converting them to integers.
    while ((s[i] >= '0') && (s[i] <= '9'))
    {
        // Converting to integers by subtract ASCII code of zero from them.  
        // Example: '3' (ASCII 51) - '0' (ASCII 48) = 3
        int digit = s[i] - '0';
        // Rounding By just checking the Max Limit and conditioning it
        // With Min Limit according to the value of sign.
        // only Edge Case -> Most min digit (-2147483648).
       /* if (res > (INT_MAX - digit) / 10)
        return (sign == 1) ? INT_MAX : INT_MIN;*/
        // Better for Memory Accessing. 
        // Making the Rounding if they exceed the positive max limit.
        // res will overflow if it is multilpied by 10 and the digit is added to it in the next
        // operation.
        // i.e. Check for overflow/underflow before updating result. 
        if (sign == 1) {
        if (res > (INT_MAX - digit) / 10) 
        {
        // Clamp to max if overflow.
        return INT_MAX;
        }
        // Use the same concept of the +ve max with the negative for simplicity.
        // According to the value of sign (-1 -> negative "not 1").
        }
         else
         {
        if (res > (INT_MAX - digit) / 10) 
        {
        // We round and return the min limit. 
        return INT_MIN;
        }
        }
        // Handling the Zeros and Eliminate Them as zero times 10 equals zero and 
        // res * 10 + 0 = resulrt * 10 (means we sucessfully added the zero)
        // Summing the result numbers to get integer as an output.
        res = res * 10 + digit;
        i++;
    }
    // Multiplying by sign to apply the '-' char as a value of - integer.
    // As long As the Negative value Comes first before the digits.
    return res * sign;
    }