// Function to return integer value of a single Roman numeral character.
// This function is substitute of using hashmap as C doesn't have built-in maps.
// We used a look-up table using switch case.
int valueof(char c) {
    // The mapped Roman to Numeral.
    switch (c) {
    case 'I':
        return 1; // Roman numeral I = 1
    case 'V':
        return 5; // Roman numeral V = 5
    case 'X':
        return 10; // Roman numeral X = 10
    case 'L':
        return 50; // Roman numeral L = 50
    case 'C':
        return 100; // Roman numeral C = 100
    case 'D':
        return 500; // Roman numeral D = 500
    case 'M':
        return 1000; // Roman numeral M = 1000
    default:
        return 0; // Invalid character → return 0.
    }
}
int romanToInt(char* s) {
    // Variable to store the integer came from Roman and be returned at the end.
    int result = 0;
    // Loop through the Roman numeral string until we reach the null terminator.
    for (int i = 0; s[i] != '\0'; i++) {
        // Value of current Roman character.
        int x = valueof(s[i]);
        // Value of next Roman character (lookahead).
        int y = valueof(s[i + 1]);
        // Case 1: current symbol is greater or equal to the next.
        // → simply add its value to the result.
        if (x >= y) {
            result += x;
        }
        // Add the difference (e.g., 5-1 = 4).
        // Skip the next character since we already used it.
        else {
            result += (y - x);
            i++;
        }
    }
    // Return the final integer value.
    return result;
}
