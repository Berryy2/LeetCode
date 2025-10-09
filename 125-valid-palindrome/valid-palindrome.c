/*****************************************************************************************************
* Using 2 ptrs approach, intializing 2 ptrs at the start and end of the string shrinking and checking 
* that their characters are equal skipping any space or special characters.
*****************************************************************************************************/
// Tried to implement the 2 helper functions just to discover that ctype.h contains them. :) 
/*int isalnum(char c)
{
    return ((c >= 'A') && (c <= 'Z') ||
            (c >= 'a') && (c <= 'z') ||
            (c >= '0') && (c <= '9'));
}*/

/*char tolower (char c)
{
    if((c >= 'A') && (c <= 'Z'))
    return c + 32;
}*/

bool isPalindrome(char* s) 
{
    // Initialize the two pointers at the start and end of the string.
    int L = 0;
    int R = strlen(s) - 1;
    // Loop while the left pointer hasn't met the right pointer.
    while(L < R)
    {
        // Skip all spaces and special characters using isalnum() for the left pointer,
        // then move it forward.
        while((L < R) && !(isalnum(s[L]))) L++;
        // Skip all spaces and special characters using isalnum() for the right pointer,
        // then move it backward.
        while((L < R) && !(isalnum(s[R]))) R--;

        // Compare the lowercase versions of the current characters.
        // If they are not equal, the string is not a palindrome.
        if(tolower(s[L]) != tolower(s[R]))
        {
            return false;
        }
        // Continue shrinking the 2 ptrs in the string.
        L++;
        R--;
    } 
    // Completing the loop means the string is a palindrome.
    return true;
}

// Thats Time complexity: O(n) & Space complexity: O(1).