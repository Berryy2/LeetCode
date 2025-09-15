// Problem is so much easier in python.
// but in c it teaches you diffrent approach like we did here "Vertical Scaning".
char* longestCommonPrefix(char** strs, int strsSize) 
{
// If there are no strings, return an empty string.
if (strsSize == 0)
return "";
// Loop character by character through the first string
// until reaching its length (strlen(strs[0])).
for(int i = 0; i < strlen(strs[0]); i++)
{
    // Store in c the current character from the first string.
    char c = strs[0][i];
    // Compare this character with the same position
    // in all the other strings.
    // Note: that j increment by whole string not character.
    for(int j = 1; j < strsSize; j++)
    {
        // 1st Condition: that i reached the end of another string
        // example: ("flower", "fly") here i = 3 at "w" reaches the end 
        // of the other string.
        // 2nd Condition: Characters don’t match at this position.
        // current char in 2nd loop strs[j][i] is not equal the char in first string
        // the char in first string with the same position.
        if((i == strlen(strs[j])) || (strs[j][i] != c))
        // We contionue copying the prefix until we see on of these conditions
        // Return the prefix built so far by copying
        // the first i characters of the first string.
        return strndup(strs[0], i); 
    }
}
// If we finish the loop without mismatches,
// then the entire first string is the common prefix.
return strs[0];
}