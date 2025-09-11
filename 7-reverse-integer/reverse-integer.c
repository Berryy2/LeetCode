//#define INT_MAX 2147483647
//#define INT_MIN -2147483648

//Problem is easy but its trick is setting the limits conditions.

int reverse(int x){
// Intialize reverse to store in the reversed number.
// reminder to add the least significant digit (Last Digit) to the reverse
int reverse = 0, reminder = 0;
// Process each digit until the number becomes 0.
while (x != 0)
{
// Calculate the reminder -> (get the least significant digit of x) .
reminder = x % 10;
// Get rid of the least significant digit of x after storing it in reminder.
x = x / 10;
// The limits condition (check for overflow & underflow) before updating
// reverse variable 
// 1) Stop before multiplying the number by 10 and exceeding the max range.
// 2) The number still in range but will exceed it when we add the reminder. 
if ((reverse > INT_MAX / 10) || ((reverse == INT_MAX) && (reminder > 7) )) 

// Overflow -> return 0 as per problem statement
return 0;
// Same condition for the -ve range.
// 1) Stop before multiplying the number by 10 and exceeding the max range.
// 2) The number still in range but will exceed it when we add the reminder.
//    and here adding by -ve = Subtracting.
if ((reverse < INT_MIN / 10) || ((reverse == INT_MIN) && (reminder < -8) )) 
// Underflow -> return 0.
return 0;
// We calaculate the reversed number digit by digit from the reminder.
reverse = reverse * 10 + reminder;
}
// We return the reversed number within the Limits set.
return reverse;
}

// Another approach of solving the example
// by just solving as unsigned and then if it has -ve sign 
// we Subtract the reversed number from zero to get the -ve reversed number.

/*unsigned int temp = 0, i = 0;
if (i == INT_MIN) temp = x;
else temp = abs(x);
if (x < 0) i = 1;
int reverse = 0;
while (temp > 0)
{
int remind = temp % 10;
if (reverse > (INT_MAX / 10)) return 0;
reverse = reverse * 10 + remind;
temp /= 10;
}
if (i)
reverse = 0 -  reverse;
return reverse;
}*/