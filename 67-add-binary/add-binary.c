// In our approach, we will use a carry variable to handle bit-wise addition, knowing that:
// a) 2 % 2 is 0 and then the carry / 2 = 1 is like 1 + 1 = 0 and carry 1.
// b) 1 % 2 is 1 and then the carry / 2 = 0 is like 1 + 0 = 1 and carry 0.
// c) 0 % 2 is 0 and then the carry / 2 = 0 is like 0 + 0 = 0 and carry 0.
// Lastly, we will return string + remaining size to skip any undefined (garbage) value.
// With this logic, we can process both strings from right to left and build the result. 
char* addBinary(char* a, char* b)
{
    // We will get the lengths of both binary strings.
    int sizeA = strlen(a);
    int sizeB = strlen(b);
    // Make the length of the resulted array equals the length of the largest of the 2 strings.
    // and the + 1 for the possible carry flow at the end.
    int maxSize = fmax(sizeA,sizeB) + 1;
    // Then allocate memory for the result string where +1 is for null terminator.
    char* res = (char*)malloc(maxSize + 1);
    // Null-terminate the string at the end.
    res[maxSize] = '\0';
    // Initialize carry to 0 as there is no carry at start.
    int carry = 0;
    // Loop until both strings are completely processed OR there’s a carry left.
    while((sizeA > 0) ||(sizeB > 0) || (carry >0))
    {
        // If there are still bits left in string a, add the corresponding bit to carry.
        if(sizeA > 0)
        { 
            // Convert char ('0' or '1') to integer (0 or 1)
            // also pre-decrement sizeA (you can decrement it any where in the loop).
            carry += a[--sizeA] - '0';
        }
        // If there are still bits left in string b, add the corresponding bit to carry.
        if(sizeB > 0)
        {
            // Same conversion as string a.
            carry += b[--sizeB] - '0';
        }
        // Store the current bit (carry % 2) in result from the end of res array.
        // Convert back to char ('0' or '1').
        res[--maxSize] = (carry % 2) + '0';
        // Update carry for the next iteration (either 0 or 1).
        carry /= 2;
    }
    // Return the pointer to the first valid bit of the result.
    // (+ maxSize) to skip unused leading positions as there can be no carry while
    // maxSize is at 1, that will put undefined variable in res[0].
    return res + maxSize;
}