bool IsMatching(char open, char close)
{
    return ((open == '(') && (close == ')')) || ((open == '{') && (close == '}')) ||
    ((open == '[') && (close == ']'));
}

bool isValid(char* s) 
{
    int n = strlen(s);
    char *stack = (char*)malloc(sizeof(char) * n);
    int top = -1;
    for(int i = 0; i < n; i++)
    {
        char c = s[i];
        if((c == '(') || (c == '{') ||(c == '['))
        {
            stack[++top] = c;
        }
        else
        {
            if(top == -1)
            {
                free(stack);
                return false;
            }
            if(!(IsMatching(stack[top], c)))
            {
                free(stack);
                return false;
            }
            top--;
        }
    }
    bool valid = (top == -1);
    free(stack);
    return valid;
}