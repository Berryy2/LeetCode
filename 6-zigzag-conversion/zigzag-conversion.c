// Here in zizag conversion we need to analyise and see the pattern.
char* convert(char* s, int numRows) {
    int n = strlen(s);
    // Edge case:
    // If numRows = 1 (only one row, no zigzag)
    // or numRows >= n (string too short to zigzag),
    // just return a copy of the original string.
    if ((numRows <= 1) || (numRows >= n))
    {
        // +1 for null terminator
        char* copy = (char*)malloc(n+1);
        strcpy(copy,s);
        return copy;
    }
    // Allocate memory for the result string and again + 1 for the null terminator.
    char* result = (char*)malloc(n+1);
    // Position pointer for result[]
    int pos = 0;
    // The cycle length = down (numRows) + up diagonally (numRows - 2)
    // Example: numRows = 4 → cycleLen = 6 (chars repeat every 6 steps)
    /*1      -> go row 0 again(new cycle starts)
      2    6
      3  5
      4  */ // Thats my own explanation btw xd.
    int cycleLen = 2 * numRows - 2;
    // Traverse row by row
    for (int row = 0 ; row < numRows ; row++)
    {
        // For each cycle, check positions belonging to this row.
        for (int j = row ; j < n ; j+= cycleLen)
        {   
            // Vertical Jump: characters that fall directly in this row.
            // or (on the same row).
            result[pos++] = s[j];
            if ((row != 0) && (row != numRows - 1))
            {
                // Diagonal Jump: only for middle rows (not top or bottom)
                // Pattern: index of diagonal character = j + (cycleLen - 2*row).
                // j = the vertical index in this row.
                // (cycleLen - 2*row) shifts to the diagonal position.
                int diagonalIndex = j + (cycleLen - 2 * row); 
                // Make sure we don’t go past the string length.
                if (diagonalIndex < n)
                {
                result[pos++] = s[diagonalIndex];
                }
        }
    }
}
// Don't forget the Null-terminate result.
result[pos] = '\0';
return result;
}