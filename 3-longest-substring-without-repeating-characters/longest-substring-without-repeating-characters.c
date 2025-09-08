#include "string.h"
int lengthOfLongestSubstring(char* s) {
    // We make array the size of ASCI code and check on its index if it has
    // seen before 
    // 'Seen[c] = 1' means character 'c' is inside the current substring.
    char Seen[256] = {0}; // same as int Seen as ['a'] = [97]. 
    int R = 0; // The insertion pointer to expand window and insertion.
    int L = 0; // The deletion pointer to shrink window and deletion.
    int max = 0; // The varibale used to return.
    int len = strlen(s); // Length of the string used To loop on the string.
// Sliding window approach: 
// We try to expand R as much as possible, and if we see duplicates,
// we move L to remove them.
while(R < len)
{
    if(!Seen[(unsigned char)s[R]]) //If the index value not been seen
    {                              // before we will mark it by 1  
        Seen[(unsigned char)s[R]] = 1;
        int SubArrLen = R - L + 1; // To know the Length of the substring
                                   // (+1) As index starts from 0.
        if (SubArrLen > max)       // check for max string length.
        {
            max = SubArrLen;
        }
        R++; // We then expand the insertion pointer . 
    }
    else
    {   // If the value we checked is already = 1, we then start
        // using the deletion value to uncheck the 1s.
        Seen[(unsigned char)s[L]] = 0; 
        L++; // Then move the Left pointer to shrink the window  
             // as long as the first condition is not met.
    }
}
    return max; // we then return the maximum Substring Length
                // without repeating characters.
}