char* addBinary(char* a, char* b) 
{
    int sizeA = strlen(a);
    int sizeB = strlen(b);
    int maxSize = fmax(sizeA,sizeB) + 1;
    char* res = (char*)malloc(maxSize + 1);
    res[maxSize] = '\0';
    int carry = 0;
    while((sizeA > 0) ||(sizeB > 0) || (carry >0))
    {
        if(sizeA > 0)
        { 
            carry += a[--sizeA] - '0';
        }
        if(sizeB > 0)
        {
            carry += b[--sizeB] - '0';
        }
        res[--maxSize] = (carry % 2) + '0';
        carry /= 2;
    }

    return res + maxSize;
}