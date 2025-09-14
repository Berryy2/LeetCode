int valueof (char c)
{
    switch(c)
    {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}
int romanToInt(char* s) 
{
    int result = 0;
    for(int i = 0; s[i] != '\0'; i++)
    {
    int x = valueof(s[i]);
    int y = valueof(s[i+1]);
    if (x >= y)
    {
        result += x;
    }
    else
    {
        result += (y-x);
        i++;
    }
    }
    return result;
}