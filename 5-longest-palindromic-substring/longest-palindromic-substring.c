
// Start by creating Function to expand around a given center 
// (two pointers: left & right).
// Left (Expanding to start of stirng) & right (Expanding to end of string)
// i.e -> // Expands outward while the substring remains a palindrome.
// with start and maxlen passed by refrence to keep thier value.
// start and maxlen get updated whenever a longer palindrome is found.
void ExpandAroundCenter(char *s , int n , int left , int right , int *start , int *maxlen)
    // Continue expanding while:
{   // while left didn't expand out of the begining limit of the string.
    // while right didn't expand out of the ending limit of the string.
    // and the left side char. of the center char. = the right side char.
    // Start to mark the begining of the max substring in order to return it. 
    while ((left >= 0) && (right <= n) && (s[left] == s[right]))
    {
        // We subtract the right  -  left pinter + 1 (as it begins from 0)
        // To check the current maximum substring.
        if ((right - left + 1) > *maxlen)
        {
        // We then make start placed on left to mark the start of the max
        // substring in order to return it at the end. 
        *start = left;
        // Update maxlen with the new palindrome length
        *maxlen = right - left + 1;
        }
        // Expand outward
        left--;
        right++;    
    }
}
char* longestPalindrome(char* s) {
    int start = 0, n = strlen(s), maxlen = 0;
    // Edge case of empty string.
    if (n == 0) return NULL;
    // Loop over every character as a potential center
    for (int i = 0 ; i <= n ; i++)
    {
         // Case 1: Even-length palindrome (center between i and i+1)
         ExpandAroundCenter(s,n,i,i+1,&start,&maxlen); 

        // Case 2: Odd-length palindrome (center at i)
         ExpandAroundCenter(s,n,i,i,&start,&maxlen); 
       
    }
    
    // Allocate memory for the longest palindrome substring.
    // maxlen + 1 -> for the Null operator marking the end of the string.
    char* result = (char*)malloc(maxlen+1);
    // Copy the substring into result.
    strncpy(result,s + start,maxlen);
    // Insert null terminating the string.
    result[maxlen] = '\0';
    // At the end return result.
    return result;
}