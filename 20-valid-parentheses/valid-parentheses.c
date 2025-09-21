// As C doesn't have build in stack like python and java (didn't know about java)
// we will use helper function and creation our own stack by dynamic memory allocation
// Helper function return true if the two arguments represent matching Parentheses.
bool IsMatching(char open, char close)
{
    return ((open == '(') && (close == ')')) || ((open == '{') && (close == '}')) ||
    ((open == '[') && (close == ']'));
}

bool isValid(char* s) 
{
    // Get variable equal length of string which we will use for loop condition.
    int n = strlen(s);
    // Allocate stack of size n
    char *stack = (char*)malloc(sizeof(char) * n);
    // Assign empty stack by setting our SP to -1.
    // if you are familiar with embedded systems you should know that SP
    // always should points to the top element of the stack.
    int top = -1;
    // We loop in the string to check each char.
    for(int i = 0; i < n; i++)
    {
        char c = s[i];
        // We push the open bracket to the top of the stack.
        if((c == '(') || (c == '{') ||(c == '['))
        {
            // And pre-increment top from -1 to 0 (top of stack) and store c in it.
            
            stack[++top] = c;
        }
        else
        {
            // if the stack is empty and nothing is inserted we return false.
            // there's no matching opening bracket.
            if(top == -1)
            {
                free(stack);
                return false;
            }
            // If the pushed bracket didn't match the top of stack so the pattern is wrong we 
            // should return false. (ex; (]).
            if(!(IsMatching(stack[top], c)))
            {
                free(stack);
                return false;
            }
            // Pop the opening bracket from the stack (we found its match).
            // Top pointer acts as SP so bring it back to the top of stack;
            top--;
        }
    }
    // At the end stack should be empty so that every bracket meets its match.
    bool valid = (top == -1);
    // Free the memory we allocated.
    free(stack);
    // Return the value of valid: 1) if stack is empty then every bracket meets its match so we its true.
    //                            2) if stack not emtpy so that there is an open bracket that didn't
    //                               that didn't get its closing match so we return false.
    return valid;
}