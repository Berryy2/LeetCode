// In this problem's approach we will start from the end of the string, 
// skip any uneeded space (ex: the moon__") and then start the count when we see a letter
// untill we meet any space again. 
// its simply lovely.
int lengthOfLastWord(char* s) 
{
    // Variable which will return the length of the last word.
    int length = 0;
    // Getting the last index of string to jump and start from it.
    int n = strlen(s) - 1;
    // While the string is not empty we will skip any spaces.
    while((n >= 0) && (s[n] == ' ')) 
    {
        n--;
    }
    // Meeting the first char, we will start counting the word's length untill
    // seeing a space again.
    while((n >= 0) && (s[n] != ' '))
    {
        length++;
        n--;
    }
    // At the end we return the length.
    return length;
}