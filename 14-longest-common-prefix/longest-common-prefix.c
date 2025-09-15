char* longestCommonPrefix(char** strs, int strsSize) 
{

for(int i = 0; i < strlen(strs[0]); i++)
{
    char c = strs[0][i];
    for(int j = 1; j < strsSize; j++)
    {
        if((i == strlen(strs[j])) || (strs[j][i] != c))
        return strndup(strs[0], i); 
    }
}
return strs[0];
}