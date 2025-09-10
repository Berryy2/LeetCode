bool isPalindrome(int x) {
    // Impossible to have Palindrome negative number.
    // As the negative sign on the right won't have a mirrored sign 
    if (x < 0)
    {
        return false;
    }
     // Store the original value of x to compare with its reversed version 
     // later.
    int arg = x;
    // Variable to build the reversed number.
    int opp = 0;
    // Casual reversing number condition.
    while (x > 0)
    {
    // Getting the exact number from the least significant (LSB) bit to put 
    // at first
    int rem = x % 10;
    // Again and again constraints condition :/.
    // Check for overflow before multiplying opp by 10 and adding rem.
    // (Prevents exceeding INT_MAX).
    if (opp > (INT_MAX - rem) / 10)
    return false;
    // Append the digit to the reversed number.
    opp = opp * 10 + rem;
    // Remove the last digit from x.
    x /= 10;
    }
    // The ending of our code.
    // If the reversed number equals the original, it's a palindrome.
    if (arg == opp)
    return true;
    return false;
}