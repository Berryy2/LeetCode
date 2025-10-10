bool isSubsequence(char* s, char* t) 
{
    int Len_s = strlen(s);
    int Len_t = strlen(t);
    if( Len_s == 0) return true;
    int ptr_s = 0;
    int ptr_t = 0;
    while(ptr_t < Len_t)
    {
        if(s[ptr_s ] == t[ptr_t])
        {
            ptr_s++;
        }
        if(ptr_s == Len_s)
        {
            return true;
        }
        ptr_t++;
    }  
    return false;
}