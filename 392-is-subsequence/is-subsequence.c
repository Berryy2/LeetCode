/********************************************************************************************************
* Two-pointer approach:
 * We check whether every character in string `s` appears in string `t` in the same order.
 * 1. Initialize two pointers at the start of each string.
 * 2. Traverse `t`. When characters at both pointers match, increment the `s` pointer.
 * 3. If `s` reaches its end, all its characters appeared in order → return true.
 * 4. If traversal of `t` finishes before `s` does, return false.
*********************************************************************************************************/
bool isSubsequence(char* s, char* t) 
{
    // We assign the strings lengths to a variable.
    int Len_s = strlen(s);
    int Len_t = strlen(t);

    // Corner case that if s is an empty string then it's always a subsequent. 
    if(Len_s == 0) return true;

    // Intializing the 2 ptrs at the start of each string.
    int ptr_s = 0;
    int ptr_t = 0;

    // Start looping in t
    while(ptr_t < Len_t)
    {
        // Increment s_ptr only if its char matches a char in t.
        if(s[ptr_s ] == t[ptr_t])
        {
            ptr_s++;
        }

        // If s_ptr reached the end of s string (all the characters matched), we return true.
        if(ptr_s == Len_s)
        {
            return true;
        }

        // ptr_t keeps incrementing regardless the ptr_s conditions 
        ptr_t++;
    }  
    // If the while loop completed without all s characters matched, we return false.
    return false;
}