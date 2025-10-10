bool isSubsequence(char* s, char* t) 
{
    if(strlen(s) == 0) return true;
    int ptr_s = 0;
    int ptr_t = 0;
    while(ptr_t < strlen(t))
    {
        if(s[ptr_s ] == t[ptr_t])
        {
            ptr_s++;
        }
        if(ptr_s == strlen(s))
        {
            return true;
        }
        ptr_t++;
    }  
    return false;
}