/****************************************************************************************************
* Our Approach:
* - We start with x = 0.
* - Each "++X" or "X++" increases x by 1.
* - Each "--X" or "X--" decreases x by 1.
* - We loop through all operations, check their type using strcmp(), and update x accordingly.
* Time Complexity: O(n)
* Space Complexity: O(1)
****************************************************************************************************/
int finalValueAfterOperations(char** operations, int operationsSize) 
{
    // Initialize x to zero.
    int x = 0;

    // Loop through all the operations in the given array.
    for(int i = 0; i < operationsSize; i++)
    {
        // Get the current operation string.
        char* op = operations[i];

        // If the operation is increment (either prefix or postfix),
        // increase x by 1.
        if(!strcmp(op, "X++") || !strcmp(op, "++X"))
        {
            x++;
        }
        // Otherwise, the operation must be a decrement ("--X" or "X--"),
        // so decrease x by 1.
        else
        {
            x--;
        }
    }

    // Return the final value after all operations.
    return x;
}