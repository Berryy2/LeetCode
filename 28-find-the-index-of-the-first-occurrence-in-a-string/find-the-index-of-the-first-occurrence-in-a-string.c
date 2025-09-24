int strStr(char* haystack, char* needle) 
{
    // N will track position inside the needle (pattern).
    int N = 0;

    // Get the lengths of haystack and needle.
    int lenH = strlen(haystack);
    int lenN = strlen(needle);

    // Loop through each position in haystack as a potential start of match.
    for(int i = 0; i <= lenH - 1; i++)
    {
        // If current haystack char matches the current needle char:
        if(haystack[i] == needle[N])
        {
            // Save the current haystack index as potential match start.
            int index = i;

            // Try to match subsequent characters.
            while(haystack[i] == needle[N])
            {
                i++;  // advance haystack
                N++;  // advance needle

                // If we reached the end of needle, full match found.
                if(N == lenN)
                {
                    return index; // return starting position of match
                }
            }

            // If mismatch occurs, reset i and N:
            // - put i back to starting index (so outer loop can continue at next char).
            // - reset N to 0 (restart needle matching).
            i = index;
            N = 0;
        }
    }

    // If we reach here, needle not found in haystack.
    return -1;
}
