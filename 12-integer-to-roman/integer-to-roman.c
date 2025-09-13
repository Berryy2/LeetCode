// We will struct way as its the cleanest code for me.
// We can solve itialize array and string with each index of the array (number) corresponds
// the Index of the string (Matching Roman numeral) and make the same condition will eg. i loops
// in both.
typedef struct
{
    // Integer value of the Roman numeral (e.g., 1000, 900, 500, …)
    int value;
    // String symbol of the Roman numeral (e.g., "M", "CM", "D", …)
    char* symbol;
} RomanMap;
// Mapping table: sorted from largest to smallest values.
// Includes both normal Roman numerals and subtractive forms (like 900 = "CM").
RomanMap map[] = {
    {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
    {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
    {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
};

char* intToRoman(int num) 
{
    // Create a static buffer for the result string.
    // Static → memory persists after function returns (safe to return a pointer).
    // Static is no saved in stack but in (.bss) in RAM. "I Love Embedded Btw"
    // Size 20 → more than enough (largest Roman numeral is “MMMCMXCIX” = 9 chars).
    static char result[20];
    // Start with an empty string (null-terminator at index 0).
    result[0] = '\0';
    // Loop through each Roman numeral mapping (largest → smallest).
    // sizeof(map)/sizeof(map[0]) → number of elements in the map.
    for(int i = 0 ; i < sizeof(map)/sizeof(map[0]); i++)
    {
         // While the current number is greater than or equal to the Roman value.
        while(num >= map[i].value )
        {
            // Append the Roman numeral symbol to the result string.
            strcat(result, map[i].symbol);
            // Subtract the corresponding value from num.
            num -= map[i].value;
        }
    }
// Subtract the corresponding value from num.
return result;
}