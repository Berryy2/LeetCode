int strStr(char* haystack, char* needle) 
{
int N = 0;
int lenH = strlen(haystack);
int lenN = strlen(needle);
for(int i = 0; i <= lenH - 1; i++)
{
    if(haystack[i] == needle[N])
    {
        int index = i;
        while(haystack[i] == needle[N])
        {
        i++;
        N++;
        if(N == lenN)
        {
            return index;
        }
        }
        i = index;
        N = 0;
    }
}
return -1;
}